namespace ASCII_To_Binary
{
    internal class Program
    {
        static void Main()
        {
        start:
            Console.Title = "ASCII To Binary/Binary To ASCII - Berkay Gediz";

            Console.WriteLine("Enter the character: ");
            try
            {
                char key = Convert.ToChar(Console.ReadLine());
                AsciiToBinary(key);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            Console.WriteLine("\nEnter the binary string (8 digit):");
            try
            {
                var binaries = Convert.ToString(Console.ReadLine());
                BinaryToAscii(binaries.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            Console.ReadKey();
            Console.Clear();
            goto start;
        }

        public static void AsciiToBinary(char key)
        {
            try
            {
                byte bit;
                byte asciivalue = (byte)key;
                byte[] binaries = new byte[8];
                for (int i = 0; i < binaries.Length; i++)
                {
                    bit = (byte)(asciivalue % 2);
                    asciivalue /= 2;
                    binaries[i] = bit;
                }
                Array.Reverse(binaries);

                string binarytext = string.Empty;
                foreach (byte binary in binaries)
                {
                    binarytext += binary.ToString();
                }

                for (int i = 0; i < binarytext.Length; i++)
                {
                    Console.Write(binarytext[i]);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        public static char BinaryToAscii(string binary)
        {
            try
            {
                int asciivalue = 0;
                for (int i = 0; i < binary.Length; i++)
                {
                    if (binary[i] == '1')
                    {
                        asciivalue += (int)Math.Pow(2, 7 - i);
                    }
                }

                Console.WriteLine($"ASCII: {asciivalue} - Char: {(char)asciivalue}");
                return (char)asciivalue;
            }
            catch (Exception e)
            {
                throw new ArgumentException(e.ToString());
            }
        }
    }
}