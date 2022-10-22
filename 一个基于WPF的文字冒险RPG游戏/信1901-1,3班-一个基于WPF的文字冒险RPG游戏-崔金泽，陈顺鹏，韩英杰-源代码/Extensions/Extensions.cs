﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.IO.Compression;
using System.Threading;
using System.Threading.Tasks;

namespace Extensions
{
    public static class MyExtensions
    {
        /// <summary>Adds multiple ranges to a List.</summary>
        /// <typeparam name="T">Type</typeparam>
        /// <param name="list">List for others to be added to</param>
        /// <param name="lists">Lists to be added to list</param>
        public static void AddRanges<T>(this List<T> list, params IEnumerable<T>[] lists)
        {
            foreach (IEnumerable<T> currentList in lists)
                list.AddRange(currentList);
        }

        /// <summary>Determines the starting day of a given week.</summary>
        /// <param name="dt">Date used to determine the first day of the week</param>
        /// <param name="startOfWeek">Day of the week chosen to start the week</param>
        /// <returns>The starting day of a given week</returns>
        public static DateTime StartOfWeek(this DateTime dt, DayOfWeek startOfWeek)
        {
            int diff = (7 + (dt.DayOfWeek - startOfWeek)) % 7;
            return dt.AddDays(-1 * diff).Date;
        }

        /// <summary>This method converts a <see cref="TimeSpan"/> to a readable string.</summary>
        /// <param name="ts"><see cref="TimeSpan"/> to be converted.</param>
        /// <returns>Custom formatted string</returns>
        public static string ToCustomString(this TimeSpan ts) => ts.Days > 0 ? $"{ts.Days}:{ts.Hours}:{ts.Minutes}:{ts.Seconds}" : $"{ts.Hours}:{ts.Minutes}:{ts.Seconds}";

        /// <summary>Determines if this character is a comma.</summary>
        /// <param name="c">Character to be evaluated</param>
        /// <returns>Returns true if character is a comma</returns>
        public static bool IsComma(this char c) => c.Equals(',');

        /// <summary>Determines if this character is a hyphen.</summary>
        /// <param name="c">Character to be evaluated</param>
        /// <returns>Returns true if character is a hyphen</returns>
        public static bool IsHyphen(this char c) => c.Equals('-');

        /// <summary>Determines if a List is empty.</summary>
        /// <typeparam name="T">Type of List</typeparam>
        /// <param name="list">List being checked</param>
        /// <returns>Returns true if empty</returns>
        public static bool IsNullOrEmpty<T>(this IList<T> list) => list == null || list.Count < 1;

        /// <summary>Determines if a Dictionary is empty.</summary>
        /// <typeparam name="T">Type of Key</typeparam>
        /// <typeparam name="TU">Type of Value</typeparam>
        /// <param name="dictionary">Dictionary being checked</param>
        /// <returns>Returns true if empty</returns>
        public static bool IsNullOrEmpty<T, TU>(this IDictionary<T, TU> dictionary) => dictionary == null || dictionary.Count < 1;

        /// <summary>Determines if this character is a period.</summary>
        /// <param name="c">Character to be evaluated</param>
        /// <returns>Returns true if character is a period</returns>
        public static bool IsPeriod(this char c) => c.Equals('.');

        /// <summary>Determines if this character is a period or comma.</summary>
        /// <param name="c">Character to be evaluated</param>
        /// <returns>Returns true if character is a period or comma</returns>
        public static bool IsPeriodOrComma(this char c) => c.Equals('.') | c.Equals(',');

        /// <summary>Determines if this character is a space.</summary>
        /// <param name="c">Character to be evaluated</param>
        /// <returns>Returns true if character is a space</returns>
        public static bool IsSpace(this char c) => c.Equals(' ');

        /// <summary>Formats DateTime.Now to my desired string format</summary>
        /// <param name="dt">DateTime</param>
        /// <returns>Formatted DateTime.Now</returns>
        public static string NowToString(this DateTime dt) => DateTime.Now.ToString("'yyyy':'MM':'dd' 'hh':'mm':'ss' tt", new CultureInfo("en-US"));

        /// <summary>Replaces an item in a List.</summary>
        /// <typeparam name="T">Type of object being replaced</typeparam>
        /// <param name="list">List</param>
        /// <param name="original">Original item</param>
        /// <param name="replacement">Replacement item</param>
        public static void Replace<T>(this IList<T> list, T original, T replacement)
        {
            int index = list.IndexOf(original);
            if (index >= 0)
                list[index] = replacement;
        }

        /// <summary>Shuffles a List.</summary>
        /// <typeparam name="T">Generic Type</typeparam>
        /// <param name="list">List Name</param>
        public static void Shuffle<T>(this IList<T> list)
        {
            int n = list.Count;
            while (n > 1)
            {
                n--;
                int k = ThreadSafeRandom.ThisThreadsRandom.Next(n + 1);
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }

        /// <summary>Waits for an asynchronous Process to exit asynchronously.</summary>
        /// <param name="process">Process to be awaited</param>
        /// <param name="cancellationToken">Cancellation token</param>
        /// <returns>Task</returns>
        public static Task WaitForExitAsync(this Process process,
            CancellationToken cancellationToken = default(CancellationToken))
        {
            TaskCompletionSource<object> tcs = new TaskCompletionSource<object>();
            process.EnableRaisingEvents = true;
            process.Exited += (sender, args) => tcs.TrySetResult(null);
            if (cancellationToken != default(CancellationToken))
                cancellationToken.Register(tcs.SetCanceled);

            return tcs.Task;
        }
        public static void ExtractToDirectory(this ZipArchive archive, string destinationDirectoryName, bool overwrite)
        {
            if (!overwrite)
            {
                archive.ExtractToDirectory(destinationDirectoryName);
                return;
            }
            foreach (ZipArchiveEntry file in archive.Entries)
            {
                string completeFileName = Path.Combine(destinationDirectoryName, file.FullName);
                string directory = Path.GetDirectoryName(completeFileName);

                if (!Directory.Exists(directory))
                    Directory.CreateDirectory(directory);

                if (file.Name != "")
                    file.ExtractToFile(completeFileName, true);
            }
        }
    }
}