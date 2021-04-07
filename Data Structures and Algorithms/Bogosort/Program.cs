using System;
using System.Collections.Generic;
using System.Linq;

namespace generics
{
    class Shuffler<T>
    {
        public void Shuffle(List<T> list) //Shuffles our list of arbitrary type once
        {
            int n = list.Count; //Amount of elements in list. Very handy if you need to know the amount of numbers in a list. Which we do. 
            while (n > 1){
                Random rng = new Random(); //We create a new random number generator each time we run the function. For extra randomness
                n--;
                int k = rng.Next(n + 1);
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }
    }
    class BogoSorter<T>{
        public bool isSorted(List<T> list){
            List<T> listCopy = new List<T>(list);
            listCopy.Sort();

            if(Enumerable.SequenceEqual(listCopy, list)) //Because comparing generics is weird. But this works
            {
                return true; //if they are "equal", return true
            }
          return false; //if they are not "equal", return false
        }

        public List<T> bogoSort(List<T> list){
            Shuffler<T> myShuffler = new Shuffler<T>();
            int i = 0;
            while (!isSorted(list)){
                myShuffler.Shuffle(list);
                i++;
                Console.WriteLine("Shuffling... "+ i + " times");
            }

            return list;
        }
    }
    class Program
    {
        public static List<int> generateList(List<int> someList, int amount) //Generates a n-element of integer type list
        {
            Random randy = new Random(); //Meet randy, our random number generator
            for (int i = 0; i < amount; i++) //A for-loop. Very handy.
                {
                    someList.Add(randy.Next(10)); //generates a random number between 0 and 10.
                }
            return someList;
        }
        
        static void Main(string[] args)
        {
            /* Simple example of shuffle with integers
            Console.WriteLine("Hello World!"); //Hello, World!
            List<int> intList = new List<int>();
            intList = generateList(intList, 4);
            Console.WriteLine("Before shuffling:");
            Console.WriteLine(intList[0]);
            Console.WriteLine(intList[1]);
            Console.WriteLine(intList[2]);
            Console.WriteLine(intList[3]);
            Shuffler<int> myShuffler = new Shuffler<int>();
            myShuffler.Shuffle(intList);
            Console.WriteLine("After shuffling:");
            Console.WriteLine(intList[0]);
            Console.WriteLine(intList[1]);
            Console.WriteLine(intList[2]);
            Console.WriteLine(intList[3]);
            */

            //Testing bogosort on integers
            /*
            List<int> intList = new List<int>();
            intList = generateList(intList, 6);
            Console.WriteLine("Before shuffling:");
            for(int i=0;i<intList.Count;i++)
            {
                Console.WriteLine(intList[i]);
            }
            BogoSorter<int> aBadTime = new BogoSorter<int>();
            aBadTime.bogoSort(intList);
            Console.WriteLine("After shuffling:");
            for (int i = 0; i < intList.Count; i++)
            {
                Console.WriteLine(intList[i]);
            }
            */
            
            /*
            //Sorting strings.
            List<string> stringList = new List<string>();
            stringList.Add("Anna");
            stringList.Add("Book");
            stringList.Add("Samlar");
            stringList.Add("På");
            stringList.Add("Tänder");
            Console.WriteLine("Before shuffling:");
            for (int i = 0; i < stringList.Count; i++)
            {
                Console.WriteLine(stringList[i]);
            }
            BogoSorter<string> aBadTime = new BogoSorter<string>();
            aBadTime.bogoSort(stringList);
            Console.WriteLine("After shuffling:");
            for (int i = 0; i < stringList.Count; i++)
            {
                Console.WriteLine(stringList[i]);
            }
            */
        }
    }
}

    