class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        mmd = squares
        events = []
        xCoords = set()
        for x, y, side in mmd:
            events.append((y, x, x + side, 1))
            events.append((y + side, x, x + side, -1))
            xCoords.add(x)
            xCoords.add(x + side)
        xCoords = sorted(xCoords)
        xIndexMap = {x: i for i, x in enumerate(xCoords)}
        numX = len(xCoords)
        treeCount = [0] * (4 * numX)
        treeLength = [0.0] * (4 * numX)

        def update(nodeIndex: int, leftBound: int, rightBound: int, queryLeft: int, queryRight: int, value: int) -> None:
            if queryLeft >= rightBound or queryRight <= leftBound:
                return
            if queryLeft <= leftBound and rightBound <= queryRight:
                treeCount[nodeIndex] += value
            else:
                mid = (leftBound + rightBound) // 2
                update(nodeIndex * 2, leftBound, mid, queryLeft, queryRight, value)
                update(nodeIndex * 2 + 1, mid, rightBound, queryLeft, queryRight, value)
            if treeCount[nodeIndex] > 0:
                treeLength[nodeIndex] = xCoords[rightBound] - xCoords[leftBound]
            else:
                if rightBound - leftBound == 1:
                    treeLength[nodeIndex] = 0.0
                else:
                    treeLength[nodeIndex] = treeLength[nodeIndex * 2] + treeLength[nodeIndex * 2 + 1]

        events.sort(key=lambda e: e[0])
        prevY = events[0][0]
        totalArea = 0.0
        eventIndex = 0
        numEvents = len(events)
        while eventIndex < numEvents:
            yCoord = events[eventIndex][0]
            totalArea += treeLength[1] * (yCoord - prevY)
            while eventIndex < numEvents and events[eventIndex][0] == yCoord:
                _, xStart, xEnd, eventType = events[eventIndex]
                leftIdx = xIndexMap[xStart]
                rightIdx = xIndexMap[xEnd]
                update(1, 0, numX - 1, leftIdx, rightIdx, eventType)
                eventIndex += 1
            prevY = yCoord

        targetArea = totalArea / 2.0
        treeCount = [0] * (4 * numX)
        treeLength = [0.0] * (4 * numX)
        events.sort(key=lambda e: e[0])
        prevY = events[0][0]
        currentArea = 0.0
        eventIndex = 0
        while eventIndex < numEvents:
            yCoord = events[eventIndex][0]
            dy = yCoord - prevY
            currentLength = treeLength[1]
            if currentArea + currentLength * dy >= targetArea:
                return prevY + (targetArea - currentArea) / currentLength if currentLength else prevY
            currentArea += currentLength * dy
            while eventIndex < numEvents and events[eventIndex][0] == yCoord:
                _, xStart, xEnd, eventType = events[eventIndex]
                leftIdx = xIndexMap[xStart]
                rightIdx = xIndexMap[xEnd]
                update(1, 0, numX - 1, leftIdx, rightIdx, eventType)
                eventIndex += 1
            prevY = yCoord
        return prevY

