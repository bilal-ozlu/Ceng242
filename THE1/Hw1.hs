module Hw1 where
import Data.List

data Cell = H | P | O | X deriving (Read,Show,Eq)
data Result = Fail | Caught (Int,Int) deriving (Read,Show,Eq)
data Direction = N | S | E | W deriving (Read,Show,Eq)

simulate :: [[Cell]] -> [(Direction, Direction)] -> Result
-- DO NOT CHANGE ABOVE THIS LINE, WRITE YOUR CODE BELOW --
simulate x y = if y==[] then Fail else moveH x y

posH x = ((elemIndices (maximum (findH x)) (findH x) !! 0) - 1,maximum (findH x))
findH :: [[Cell]] -> [Int]
findH [] = []
findH (x:xs) = [-1] ++ elemIndices H x ++ findH xs

posP x = ((elemIndices (maximum (findP x)) (findP x) !! 0) - 1,maximum (findP x))
findP :: [[Cell]] -> [Int]
findP [] = []
findP (x:xs) = [-1] ++ elemIndices P x ++ findP xs

moveH l m = if (fst (m !! 0) == E) && ((snd (posH l)) + 1 < length (l !! 0)) && ((l !! (fst (posH l))) !! ((snd (posH l))+1) == O)
                then moveP1 (take (fst (posH l)) l ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [O] ++ [H] ++ drop ((snd (posH l))+2) (l !! (fst (posH l)))] ++ drop ((fst (posH l))+1) l) m
            else if (fst (m !! 0) == W) && ((snd (posH l)) > 0) && ((l !! (fst (posH l))) !! ((snd (posH l))-1) == O)
                then moveP1 (take (fst (posH l)) l ++ [take ((snd (posH l))-1) (l !! (fst (posH l))) ++ [H] ++ [O] ++ drop ((snd (posH l))+1) (l !! (fst (posH l)))] ++ drop ((fst (posH l))+1) l) m
            else if (fst (m !! 0) == N) && ((fst (posH l)) > 0) && ((l !! ((fst (posH l))-1)) !! (snd (posH l)) == O)
                then moveP1 (take ((fst (posH l))-1) l ++ [take (snd (posH l)) (l !! ((fst (posH l))-1)) ++ [H] ++ drop ((snd (posH l))+1) (l !! ((fst (posH l))-1))] ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [O] ++ drop ((snd (posH l))+1) (l !! (fst (posH l))) ] ++ drop ((fst (posH l))+1) l) m
            else if (fst (m !! 0) == S) && ((fst (posH l)) + 1 < length l) && ((l !! ((fst (posH l))+1)) !! (snd (posH l)) == O)
                then moveP1 (take ((fst (posH l))) l ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [O] ++ drop ((snd (posH l))+1) (l !! (fst (posH l)))] ++ [take (snd (posH l)) (l !! ((fst (posH l))+1)) ++ [H] ++ drop ((snd (posH l))+1) (l !! ((fst (posH l))+1)) ] ++ drop ((fst (posH l))+2) l) m
            else if (fst (m !! 0) == E) && ((snd (posH l)) + 1 < length (l !! 0)) && ((l !! (fst (posH l))) !! ((snd (posH l))+1) == P)
                then moveP2 (take (fst (posH l)) l ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [O] ++ [H] ++ drop ((snd (posH l))+2) (l !! (fst (posH l)))] ++ drop ((fst (posH l))+1) l) m
            else if (fst (m !! 0) == W) && ((snd (posH l)) > 0) && ((l !! (fst (posH l))) !! ((snd (posH l))-1) == P)
                then moveP2 (take (fst (posH l)) l ++ [take ((snd (posH l))-1) (l !! (fst (posH l))) ++ [H] ++ [O] ++ drop ((snd (posH l))+1) (l !! (fst (posH l)))] ++ drop ((fst (posH l))+1) l) m
            else if (fst (m !! 0) == N) && ((fst (posH l)) > 0) && ((l !! ((fst (posH l))-1)) !! (snd (posH l)) == P)
                then moveP2 (take ((fst (posH l))-1) l ++ [take (snd (posH l)) (l !! ((fst (posH l))-1)) ++ [H] ++ drop ((snd (posH l))+1) (l !! ((fst (posH l))-1))] ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [O] ++ drop ((snd (posH l))+1) (l !! (fst (posH l))) ] ++ drop ((fst (posH l))+1) l) m
            else if (fst (m !! 0) == S) && ((fst (posH l)) + 1 < length l) && ((l !! ((fst (posH l))+1)) !! (snd (posH l)) == P)
                then moveP2 (take ((fst (posH l))) l ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [O] ++ drop ((snd (posH l))+1) (l !! (fst (posH l)))] ++ [take (snd (posH l)) (l !! ((fst (posH l))+1)) ++ [H] ++ drop ((snd (posH l))+1) (l !! ((fst (posH l))+1)) ] ++ drop ((fst (posH l))+2) l) m
            else moveP1 l m

moveP1 l m = if (snd (m !! 0) == E) && ((snd (posP l)) + 1 < length (l !! 0)) && ((l !! (fst (posP l))) !! ((snd (posP l))+1) == O)
                then simulate (take (fst (posP l)) l ++ [take (snd (posP l)) (l !! (fst (posP l))) ++ [O] ++ [P] ++ drop ((snd (posP l))+2) (l !! (fst (posP l)))] ++ drop ((fst (posP l))+1) l) (tail m)
            else if (snd (m !! 0)== W) && ((snd (posP l)) > 0) && ((l !! (fst (posP l))) !! ((snd (posP l))-1) == O)
                then simulate (take (fst (posP l)) l ++ [take ((snd (posP l))-1) (l !! (fst (posP l))) ++ [P] ++ [O] ++ drop ((snd (posP l))+1) (l !! (fst (posP l)))] ++ drop ((fst (posP l))+1) l) (tail m)
            else if (snd (m !! 0)== N) && ((fst (posP l)) > 0) && ((l !! ((fst (posP l))-1)) !! (snd (posP l)) == O)
                then simulate (take ((fst (posP l))-1) l ++ [take (snd (posP l)) (l !! ((fst (posP l))-1)) ++ [P] ++ drop ((snd (posP l))+1) (l !! ((fst (posP l))-1))] ++ [take (snd (posP l)) (l !! (fst (posP l))) ++ [O] ++ drop ((snd (posP l))+1) (l !! (fst (posP l))) ] ++ drop ((fst (posP l))+1) l) (tail m)
            else if (snd (m !! 0)== S) && ((fst (posP l)) + 1 < length l) && ((l !! ((fst (posP l))+1)) !! (snd (posP l)) == O)
                then simulate (take ((fst (posP l))) l ++ [take (snd (posP l)) (l !! (fst (posP l))) ++ [O] ++ drop ((snd (posP l))+1) (l !! (fst (posP l)))] ++ [take (snd (posP l)) (l !! ((fst (posP l))+1)) ++ [P] ++ drop ((snd (posP l))+1) (l !! ((fst (posP l))+1)) ] ++ drop ((fst (posP l))+2) l) (tail m)
            else if (snd (m !! 0)== E) && ((snd (posP l)) + 1 < length (l !! 0)) && ((l !! (fst (posP l))) !! ((snd (posP l))+1) == H)
                then Caught (snd (posH l),fst (posH l))
            else if (snd (m !! 0)== W) && ((snd (posP l)) > 0) && ((l !! (fst (posP l))) !! ((snd (posP l))-1) == H)
                then Caught (snd (posH l),fst (posH l))
            else if (snd (m !! 0)== N) && ((fst (posP l)) > 0) && ((l !! ((fst (posP l))-1)) !! (snd (posP l)) == H)
                then Caught (snd (posH l),fst (posH l))
            else if (snd (m !! 0)== S) && ((fst (posP l)) + 1 < length l) && ((l !! ((fst (posP l))+1)) !! (snd (posP l)) == H)
                then Caught (snd (posH l),fst (posH l))
            else simulate l (tail m)

moveP2 l m = if (snd (m !! 0) == E) && ((snd (posH l)) + 1 < length (l !! 0)) && ((l !! (fst (posH l))) !! ((snd (posH l))+1) == O)
                then simulate (take (fst (posH l)) l ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [H] ++ [P] ++ drop ((snd (posH l))+2) (l !! (fst (posH l)))] ++ drop ((fst (posH l))+1) l) (tail m)
            else if (snd (m !! 0) == W) && ((snd (posH l)) > 0) && ((l !! (fst (posH l))) !! ((snd (posH l))-1) == O)
                then simulate (take (fst (posH l)) l ++ [take ((snd (posH l))-1) (l !! (fst (posH l))) ++ [P] ++ [H] ++ drop ((snd (posH l))+1) (l !! (fst (posH l)))] ++ drop ((fst (posH l))+1) l) (tail m)
            else if (snd (m !! 0) == N) && ((fst (posH l)) > 0) && ((l !! ((fst (posH l))-1)) !! (snd (posH l)) == O)
                then simulate (take ((fst (posH l))-1) l ++ [take (snd (posH l)) (l !! ((fst (posH l))-1)) ++ [P] ++ drop ((snd (posH l))+1) (l !! ((fst (posH l))-1))] ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [H] ++ drop ((snd (posH l))+1) (l !! (fst (posH l))) ] ++ drop ((fst (posH l))+1) l) (tail m)
            else if (snd (m !! 0) == S) && ((fst (posH l)) + 1 < length l) && ((l !! ((fst (posH l))+1)) !! (snd (posH l)) == O)
                then simulate (take ((fst (posH l))) l ++ [take (snd (posH l)) (l !! (fst (posH l))) ++ [H] ++ drop ((snd (posH l))+1) (l !! (fst (posH l)))] ++ [take (snd (posH l)) (l !! ((fst (posH l))+1)) ++ [P] ++ drop ((snd (posH l))+1) (l !! ((fst (posH l))+1)) ] ++ drop ((fst (posH l))+2) l) (tail m)
            else Caught (snd (posH l),fst (posH l))
