-- Kyle Krueger April 30, 2023 Quicksort with timing

--Import used to time execution
import System.CPUTime
--Import used to generate random array
import System.Random 
import Data.Array 

main :: IO ()
main = do
  --List to be sorted
  let myList = [8, 3, 4, 5, 7, 9, 0, 10, 1, 2, 7, 5, 43, 23, 12]
  let myList2 = [15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
  
  --Generating the random list 
  gen <- newStdGen
  let randomInts = take 1000 $ randomRs (1, 1000) gen 
  let myListRandom = array (0,999) (zip [0..] randomInts)
  
  putStrLn $ "Input list: " ++ show myList
  putStrLn $ "Input list 2: " ++ show myList2
  putStrLn $ "Input list Random: " ++ show (elems myListRandom)
  
  --Call the Quicksort Algorithm on each list and time it
  --List 1
  start <- getCPUTime
  let sortedList = quicksort myList
  end <- getCPUTime 
  
  -- List 2
  start2 <- getCPUTime
  let sortedList2 = quicksort myList2
  end2 <- getCPUTime
  
  --List Random 
  startRandom <- getCPUTime
  let sortedListRandom = quicksort (elems myListRandom)
  endRandom <- getCPUTime
  
  --Calculate Elaplsed Time 
  let elapsedTime = fromIntegral (end - start) / (10^12)
  let elapsedTime2 = fromIntegral (end2 - start2) / (10^12)
  let elapsedTimeRandom = fromIntegral (endRandom - startRandom) / (10^12)
  
  --Output Final results
  putStrLn $ "Sorted list: " ++ show sortedList
  putStrLn $ "Elapsed time: " ++ show elapsedTime ++ " seconds"
  putStrLn $ "Sorted list 2: " ++ show sortedList2
  putStrLn $ "Elapsed time: " ++ show elapsedTime2 ++ " seconds"
  putStrLn $ "Sorted list random: " ++ show sortedListRandom
  putStrLn $ "Elapsed time: " ++ show elapsedTimeRandom ++ " seconds"


--Mergesort 
  putStrLn $"---------MERGESORT----------"
   --Call the Quicksort Algorithm on each list and time it
  --List 1
  mstart <- getCPUTime
  let msortedList = mergesort myList
  mend <- getCPUTime 
  
  -- List 2
  mstart2 <- getCPUTime
  let msortedList2 = mergesort myList2
  mend2 <- getCPUTime
  
  --List Random 
  mstartRandom <- getCPUTime
  let msortedListRandom = mergesort (elems myListRandom)
  mendRandom <- getCPUTime
  
  --Calculate Elaplsed Time 
  let melapsedTime = fromIntegral (mend - mstart) / (10^12)
  let melapsedTime2 = fromIntegral (mend2 - mstart2) / (10^12)
  let melapsedTimeRandom = fromIntegral (mendRandom - mstartRandom) / (10^12)
  
  --Output Final results
  putStrLn $ "Sorted list: " ++ show msortedList
  putStrLn $ "Elapsed time: " ++ show melapsedTime ++ " seconds"
  putStrLn $ "Sorted list 2: " ++ show msortedList2
  putStrLn $ "Elapsed time: " ++ show melapsedTime2 ++ " seconds"
  putStrLn $ "Sorted list random: " ++ show msortedListRandom
  putStrLn $ "Elapsed time: " ++ show melapsedTimeRandom ++ " seconds"
 
quicksort :: [Int] -> [Int]
--This is the base case, an empty list is already sorted 
quicksort [] = []
--This is for our normal cases 
quicksort list = quicksort left_list ++ [pivot] ++ quicksort right_list
  where
    --Our pivot will be the first element of our list 
    pivot = head list
    -- Elements less than our pivot will go into the left list 
    left_list = filter (<=pivot) (tail list)
    -- Elements greater than our pivot will go into the right list 
    right_list = filter (>pivot) (tail list)
    
mergesort :: [Int] -> [Int]
--Base case, empty list 
mergesort [] = [] 
--Case where input list is only a single element 
mergesort [x] = [x]
--Every other case 
mergesort xs = merge (mergesort left) (mergesort right)
    where 
        --Split input list into two halves
        (left, right) = split xs
        split xs = splitAt (length xs `div` 2) xs 
        
        merge [] ys = ys 
        merge xs [] = xs 
        merge (x:xs) (y:ys) 
            --if first element of list is <= first element of second list
            -- add first element to output list and merge remaining elements 
            -- of the first list with the second list 
            | x <= y    = x: merge xs (y:ys)
            --else, add the first element of the second list to the output list 
            -- and merge the remaining elements of the second list with the first
            | otherwise = y: merge (x:xs) ys 

