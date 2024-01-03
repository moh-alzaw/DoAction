# DoAction
In C++, control flow such as executing code once or a certain amount of times can be tedious. Now you can easily do so.  
For Unreal Engine C++ programmers, this can be especially useful as there is no built in "Do Once" or "Do N" C++ equivalent.  
DoAction works by allowing code to be executed a specific amount of times before "locking" in which the code will no longer be executed unless demanded to "unlock".  

## Setting Up
### Step 1:
Download the files in the respository and add them to your C++ or Unreal Engine project.  
#### C++:
Simply add it to your project directory.  
#### Unreal Engine:
Add them to the source folder of your Unreal Engine project directory.  
Example directory: MyGame\Source\MyGame
### Step 2:
Use ```#include "DoAction.h"``` for any C++ (.cpp) or Header (.h) files that will use DoAction.  
  
## How to Use
### Functions
To use DoAction, first begin by creating an instance of the class DoAction.  
```DoAction NewDoActionInstance;```  
Next, you can assign it to a new DoAction constructor and place in parameters.  
```NewDoActionInstance = DoAction(std::function<void()> function = [](){}, int maximumTimes = 1, bool startLocked = false);```  
- Constructor Parameters  
  - **function:** What function should DoAction execute. You can also directly place your code by using ```[this](){ // PLACE CODE IN HERE }```  
  - **maximumTimes:** How many times should DoAction allow the code to be executed. (More specifically how many times should the instance allow the Do() function to be called before being locked.)  
  - **startLocked:** Should the code be locked by default?  

Now you can call the function/code that you have assigned to the DoAction instance by using the Do() function.    
```NewDoActionInstance.Do();```    
And once it has been called the maximum amount of times you have set it to, it will "lock" which prevents any further execution of the function/code provided.    
It is also possible to "unlock" or allow the execution of the function/code after it has been locked. To do so, simply use the Reset() function in the instance of DoAction that you wish to unlock.   
```NewDoActionInstance.Reset(bool onlyIfLocked = false);```    
- Reset() Function Parameters  
  - **onlyIfLocked:** It will allow you to reset the corresponding instance of DoAction ONLY IF that instance is locked.  

Need to check if the instance is locked or not? No problem! Simply use the GetIsLocked() function which returns a boolean.  
```NewDoActionInstance.GetIsLocked();```    
  
### Variables  
```
std::function<void()> Function;
int MaximumTimes;
bool StartLocked;
int NumberOfTimesExecuted;
```  

- Public Variables
  - **Function:** The function/code that the DoAction instance will execute (unless locked).  
  - **MaximumTimes:** Maximum amount of times that the function/code in the variable _Function_ can be executed before being locked.  
  - **StartLocked:** Should the DoAction instance be locked by default? This also applies for if the instance is reset.  
  - **NumberOfTimesExecuted:** Amount of times the function/code in the variable _Function_ has been executed.  
