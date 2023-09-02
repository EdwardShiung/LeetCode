//[1st]
var getIntersectionNode = function(headA, headB) {

    let pointA = headA;
    let pointB = headB;

    while(pointA != pointB){
        //pointA
        if(pointA === null){
            pointA = headB;
        }else{
            pointA = pointA.next;
        }
        //pointB
        if(pointB === null){
            pointB = headA;
        }else{
            pointB = pointB.next;
        }
    }

    return pointA;

};

/*

    1. First list set 'X'; Second list set 'Y'; the common part of two routes is set as the 'Z' variable.
    2. So, X + Z = Y + Z
    3. If pointA === pointB, the while loop stop, and then it will find out the intersection.


 */