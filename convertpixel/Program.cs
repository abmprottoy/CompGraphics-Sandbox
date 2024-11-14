using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace convertpixel
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Image dimensions
            int width = 500;
            int height = 500;

            Console.WriteLine("Enter pixel coordinates (x, y) to convert to NDC (or type 'exit' to quit):");

            while (true)
            {
                try
                {
                    // Prompt for input
                    Console.Write("Enter x coordinate: ");
                    string xInput = Console.ReadLine();

                    if (xInput.ToLower() == "exit")
                        break;

                    Console.Write("Enter y coordinate: ");
                    string yInput = Console.ReadLine();

                    if (yInput.ToLower() == "exit")
                        break;

                    // Parse input
                    int xPixel = int.Parse(xInput);
                    int yPixel = int.Parse(yInput);

                    // Validate input
                    if (xPixel < 0 || xPixel >= width || yPixel < 0 || yPixel >= height)
                    {
                        Console.WriteLine("Coordinates must be within the range of 0 to 499.");
                        continue;
                    }

                    // Convert to NDC
                    double xNDC = (2.0 * xPixel / width) - 1;
                    double yNDC = 1 - (2.0 * yPixel / height);

                    // Display result
                    Console.WriteLine($"NDC Coordinates: (x: {xNDC:F2}, y: {yNDC:F2})\n");
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input. Please enter integer values.");
                }
            }

            Console.WriteLine("Program terminated.");
        }
    }
}
