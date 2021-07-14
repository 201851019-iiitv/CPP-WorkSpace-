// Time complexity O(N^2) and space O(1)

var arr=[3,5,-4,5,8,11,1,-4,6];
var target=7;

getTargetSum=(arr,target)=>
{

    for(let i=0;i<arr.length;i++){
      for(let j=i+1;j<arr.length;j++){

            if(target===arr[i]+arr[j])
                return [arr[i],arr[j]];
            
            
            
            }

    }




    return -1;

}


console.log(getTargetSum(arr,target));


// Time complexity O(N) and space O(N)

getTarget=()=>{





};
