using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace SVG_to_GLUT_Exporter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void openSVGBtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Filter = "SVG Files (*.svg)|*.svg|All files (*.*)|*.*"
            };

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = openFileDialog.FileName;
                List<string> coordinates = ParseSvg(filePath);
                lstCoordinates.Items.Clear();
                foreach (var coord in coordinates)
                {
                    lstCoordinates.Items.Add(coord);
                }
            }
        }

        private List<string> ParseSvg(string filePath)
        {
            List<string> coordinatesList = new List<string>();
            XmlDocument doc = new XmlDocument();
            doc.Load(filePath);

            // SVG's width and height can be used to calculate normalized coordinates
            XmlNode svgRoot = doc.DocumentElement;
            float svgWidth = float.Parse(svgRoot.Attributes["width"].Value);
            float svgHeight = float.Parse(svgRoot.Attributes["height"].Value);

            // Parse different SVG shapes
            foreach (XmlNode node in svgRoot.ChildNodes)
            {
                switch (node.Name)
                {
                    case "circle":
                        coordinatesList.Add(ParseCircle(node, svgWidth, svgHeight));
                        break;
                    case "rect":
                        coordinatesList.Add(ParseRect(node, svgWidth, svgHeight));
                        break;
                    case "line":
                        coordinatesList.Add(ParseLine(node, svgWidth, svgHeight));
                        break;
                    case "polygon":
                        coordinatesList.Add(ParsePolygon(node, svgWidth, svgHeight));
                        break;
                    case "polyline":
                        coordinatesList.Add(ParsePolyline(node, svgWidth, svgHeight));
                        break;
                        // Add more cases as needed
                }
            }

            return coordinatesList;
        }

        private string ParseCircle(XmlNode node, float width, float height)
        {
            float cx = float.Parse(node.Attributes["cx"].Value);
            float cy = float.Parse(node.Attributes["cy"].Value);
            float r = float.Parse(node.Attributes["r"].Value);

            // Convert to OpenGL coordinates
            cx = SvgToGlutCoord(cx, width);
            cy = SvgToGlutCoord(cy, height);
            r = r / Math.Max(width, height) * 2; // Normalized radius

            return $"Circle - Center: ({cx}, {cy}), Radius: {r}";
        }

        private string ParseRect(XmlNode node, float width, float height)
        {
            float x = float.Parse(node.Attributes["x"].Value);
            float y = float.Parse(node.Attributes["y"].Value);
            float w = float.Parse(node.Attributes["width"].Value);
            float h = float.Parse(node.Attributes["height"].Value);

            // Convert to OpenGL coordinates
            float x1 = SvgToGlutCoord(x, width);
            float y1 = SvgToGlutCoord(y, height);
            float x2 = SvgToGlutCoord(x + w, width);
            float y2 = SvgToGlutCoord(y + h, height);

            return $"Rectangle - Bottom Left: ({x1}, {y1}), Top Right: ({x2}, {y2})";
        }

        private string ParseLine(XmlNode node, float width, float height)
        {
            float x1 = float.Parse(node.Attributes["x1"].Value);
            float y1 = float.Parse(node.Attributes["y1"].Value);
            float x2 = float.Parse(node.Attributes["x2"].Value);
            float y2 = float.Parse(node.Attributes["y2"].Value);

            // Convert to OpenGL coordinates
            x1 = SvgToGlutCoord(x1, width);
            y1 = SvgToGlutCoord(y1, height);
            x2 = SvgToGlutCoord(x2, width);
            y2 = SvgToGlutCoord(y2, height);

            return $"Line - Start: ({x1}, {y1}), End: ({x2}, {y2})";
        }

        private string ParsePolygon(XmlNode node, float width, float height)
        {
            string points = node.Attributes["points"].Value;
            return "Polygon - Points: " + ParsePoints(points, width, height);
        }

        private string ParsePolyline(XmlNode node, float width, float height)
        {
            string points = node.Attributes["points"].Value;
            return "Polyline - Points: " + ParsePoints(points, width, height);
        }

        private string ParsePoints(string points, float width, float height)
        {
            string[] coords = points.Split(' ');
            List<string> glutCoords = new List<string>();

            foreach (string coord in coords)
            {
                string[] xy = coord.Split(',');
                float x = float.Parse(xy[0]);
                float y = float.Parse(xy[1]);

                // Convert to OpenGL coordinates
                x = SvgToGlutCoord(x, width);
                y = SvgToGlutCoord(y, height);

                glutCoords.Add($"({x}, {y})");
            }

            return string.Join(" ", glutCoords);
        }

        private float SvgToGlutCoord(float svgCoord, float maxDimension)
        {
            return (svgCoord / maxDimension) * 2.0f - 1.0f; // Normalize to -1 to 1
        }
    }
}
