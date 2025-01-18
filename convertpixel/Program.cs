using System;
using System.IO;

namespace convertpixel
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Image dimensions
            int width = 1025;
            int height = 1025;

            string filePath = "NDC_Output.cpp";

            Console.WriteLine("Enter pixel coordinates (x, y) to convert to NDC (or type 'exit' to quit):");

            while (true)
            {
                try
                {
                    // Prompt for input
                    Console.Write("Enter x coordinate: ");
                    string xInput = Console.ReadLine();

                    if (xInput.ToLower() == "next") 
                    {
                        File.AppendAllText(filePath, Environment.NewLine);
                        Console.Write("Enter x coordinate: ");
                        xInput = Console.ReadLine();
                    }
                        

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
                        Console.WriteLine($"Coordinates must be within the range of 0 to {width} for width and 0 to {height} for height.");
                        continue;
                    }

                    // Convert to NDC
                    double xNDC = (2.0 * xPixel / width) - 1;
                    double yNDC = 1 - (2.0 * yPixel / height);

                    // Display result
                    Console.WriteLine($"NDC Coordinates: (x: {xNDC:F2}, y: {yNDC:F2})\n");
                    string glVertex2fLine = $"glVertex2f({xNDC:F2}f, {yNDC:F2}f);";

                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine($"{glVertex2fLine}\n");
                    Console.ResetColor();

                    // Save to file
                    File.AppendAllText(filePath, glVertex2fLine + Environment.NewLine);
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input. Please enter integer values.");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"An error occurred: {ex.Message}");
                }
            }

            Console.WriteLine("Program terminated.");
        }
    }
}
