// STRIVER SHEET ====>

 // q1-> Recursive ways to reverse a ll // TIME COM -> O(N) , SPACE => O(1) //
 //Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]

 ListNode* reverseList(ListNode* head) {
          if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        ListNode* temp = head->next;
        temp->next = head;
       head->next = NULL;
        return nnode;
    }

//q2->Tortoise-Hare-Approach -> find middle of ll //

  ListNode* middleNode(ListNode* head) {
         ListNode *slow = head  ,  *fast = head  ;
        
        while( fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
           
          return slow;
    }

//q3  Merge Two Sorted Lists ==>
//Input: list1 = [1,2,4], list2 = [1,3,4] Output: [1,1,2,3,4,4] 
// APP#1 => Time comp => o(N+M) == Space comp // do BY MERGE SORT ALGO // take space comp 
 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         if(list1 == NULL ){
               return list2 ;
         }
         if(list2 == NULL){
               return list1 ;
         }
        ListNode* h1 = list1 ;
        ListNode* h2 = list2 ;
            ListNode* root = new ListNode(-1);
            ListNode* h3 = root;

           while(h1 != NULL && h2 != NULL){
                if(h1->val <= h2->val){
                    root->next = new ListNode(h1->val);
                    h1 = h1->next;
                    root = root->next;
                }else{
                    root->next = new ListNode(h2->val);
                      h2 = h2->next;
                      root = root->next;
                }
           }

           while(h1 != NULL){
                     root->next = new ListNode(h1->val);
                    h1 = h1->next;
                     root = root->next;
           }

           while(h2 != NULL){
                    root->next = new ListNode(h2->val);
                      h2 = h2->next;
                   root = root->next;
           }
     
       return h3->next;
    }

  //optimized APProach -> take only time -> O(N+M) , space = o(1)//
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if list1 happen to be NULL
		// we will simply return list2.
ListNode *l1 = list1;
        ListNode* l2 = list2;

		if(l1 == NULL){
			return l2;
		}

		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 

		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer

		// we wall call recursively l1 -> next and whole l2 list.

		if(l1 -> val <= l2 -> val)
        {

			l1 -> next = mergeTwoLists(l1 -> next, l2);

			return l1;

		}

		// we will call recursive l1 whole list and l2 -> next

		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;          
    }
        }

// q4 Remove Nth Node From End of List --->
//Input: head = [1,2,3,4,5], n = 2  , output: [1,2,3,5]

   ListNode* removeNthFromEnd(ListNode* head, int n) {
          if(head == NULL){
              return NULL;
          }
      ListNode* curr = head , *prev = NULL ;
         int c = 1;
      while(curr->next != NULL){
            c++;
          curr = curr->next ;
      }  
             
    // 1st edge case // if head = [1,2] and n = 2 return 2 as ans ;
        if(c == n){
     head =  head->next;        
    return head;           
    }

      int j = (c - n + 1);
       curr = head ;

      while(j > 1){
          prev = curr;
          curr = curr->next;
          j--;
      }
               prev->next = curr->next ;
      return head;
    }

//q5 add 2 no. in the ll --->
//Input: l1 = [2,4,3], l2 = [5,6,4]  , output: [7,0,8] , explanation: 342 + 465 = 807.

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ans is like a dummy node that stores -1 on them //
        ListNode *ans = new ListNode(-1);
        // curr is like a dummy node //
      ListNode *p = l1 , *q = l2 , *curr = ans;
       int c = 0;

       while(p != NULL || q != NULL){
    int u = (p != NULL) ? p->val : 0 ;
      int v = (q != NULL) ? q->val : 0 ;

       int sum = (u + v + c);
      c = sum/10 ;

       curr->next = new ListNode(sum % 10);
        curr = curr->next;

         if(p != NULL) p = p->next;
          if(q != NULL) q = q->next;
       }
    
      if(c > 0){
          curr->next = new ListNode(c);
      }

      return ans->next;
    }

//q6->cycle detection in a ll --->
// #BRute force app ---> time = O(N) == space //
//IN BRUTE APPN ALWAYS USE HASHTABLE TO STORE NODE DATA IN THE QUES OF LL CYCLE RELATED //

class Solution {
public:
    bool hasCycle(ListNode *head) {
         unordered_set<ListNode*> m;

    while(head != NULL) {
        if(m.find(head) != m.end()) return true;
        m.insert(head);
        head = head->next;
    }
    return false;
    }

// q7 -> check ll is palindromic or not :--> ist is brute force then 2nd is optimized app
//ist -> time == space ==> o(n) //

   bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}

//2nd -->
//Time Complexity: O(N/2)+O(N/2)+O(N/2)
//Reason: O(N/2) for finding the middle element, reversing the list from the middle element, and traversing again to find palindrome respectively.
    bool isPalindrome(ListNode* head) {

        ListNode* fast = head;

        ListNode* slow = head;

		

		//Step 1: Find the mid Element

        

		while(fast != NULL && fast->next != NULL){

            slow = slow->next;

            fast = fast->next->next;

        }

		

		//Step 2:  Reverse the linked list by calling reverse func

		

        slow = reverseList(slow);

       

		

		// Step 3: Compare the linked list

        while(slow != NULL){

            

            if(head->val != slow->val)

                return false;

            

            head = head->next;

            slow = slow->next;

        }

        return true;        

    }

//Q8  Intersection of Two Linked Lists  ---> DO IT AGAIN IN LEETCODE 
// APP #1 -> Time comp => O(M * N)//
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
           while(headB != NULL) {
        ListNode* temp = headA;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == headB){
                return headB ;
            }
            temp = temp->next;
        }
        headB = headB->next;
    }
    //intersection is not present between the lists return null
    return NULL;
    }

// APP #2 -> Time comp => O(M) + O(N) , SPACE => O(N) FOR USING UNORDERD SET//

unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

// APP#3 --> Time Complexity: O(2*max(length of list1,length of list2)) Reason: Uses the same concept of difference of lengths of two lists.

 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* ptr1 = headA;

        ListNode* ptr2 = headB;   

        int c1,c2;

        c1 = c2 = 0;

        while(ptr1 != NULL)

        {

            c1++;

            ptr1 = ptr1->next;

        }

        while(ptr2 != NULL)
        {

            c2++;

            ptr2 = ptr2->next;

        }

        ptr1 = headA;

        ptr2 = headB;

        int diff = abs(c1-c2);

        if(c1 > c2)

        {

            for(int i=0;i<diff;i++)

            {

                ptr1 = ptr1->next;

            }

        }

        else

        {

            for(int i=0;i<diff;i++)

            {

                ptr2 = ptr2->next;

            }

        }
         
           
        while(ptr1 != ptr2)

        {

            ptr1 = ptr1->next;

            ptr2 = ptr2->next;

        }
        
        if(ptr1)

            return ptr1;

    

        return NULL;

        
    }

// q9---> Given the head of a linked list, rotate the list to the right by k places.//
//Input: head = [1,2,3,4,5], k = 2 , output: [4,5,1,2,3]

    ListNode* rotateRight(ListNode* head, int k) {
        // firstly find length of the ll and last node --> tail node
        if(k == 0 || head == NULL){
            return head;
        }
     ListNode* tail =  head, *curr = head ;
     int len = 1;
   
   while(tail->next != NULL ){
       len++;
       tail=tail->next;
   }
    tail->next = head;

      k = k%len ;
     int skip = len - k;
    
      while(skip > 1){
          skip--;
     curr=curr->next;
   }
     
     head = curr->next;
     curr->next = NULL;

     return head;
    }

 //Q10 --> Reverse node in kth grp :-

ListNode* ReverseList(ListNode *head, int k, int length)
{

   	//Base case 
    if (length < k) return head;

   	//step 1 -> reverse first k element only

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp = NULL; 
    int count = 0;

    while ((curr != NULL) && (count < k))
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }

   	//Step 2 -> Make a recursive call if node is avilable after k
    if (temp != NULL)
    {
        head->next = ReverseList(temp, k, length - k);
    }

   	//step 3 -> return previous beacuse eventually our previous become head of given Node
    return prev;
}


class Solution
{
    public:
        ListNode* reverseKGroup(ListNode *head, int k)
        {
            int length = getLength(head);
            return ReverseList(head, k, length);
        }
};

//Q11 Remove Duplicates from Sorted Array
// TIME COMP --> O(N) , SPACE = O(1) // DO IT AGAIN 
int removeDuplicates(vector<int>& nums) {
        int prev = nums[0] ;
        int c = 1 ;// bec we count ist element already in mums[i] ;

        for(int i=1;i<nums.size();i++){
            if(prev != nums[i] ){
                 nums[c] = nums[i];
                 c++;
            }
            prev = nums[i];
        }

        return c;
    }

// end of the file //
