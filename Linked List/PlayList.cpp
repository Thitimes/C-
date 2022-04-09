#include "PlayList.h"

PlayList::PlayList()
{
    currSong = -1;
    totalSong = 0;
	head = nullptr;
	tail = nullptr;
    currentSong = nullptr;
  
  
}

PlayList::~PlayList()
{
    Node* Temp = head;
    while (Temp != nullptr) {
        Node* Temp2 = Temp;
        Temp = Temp->next;
        free(Temp2);
    }
}
void PlayList::AddSong(const Song& s) 
{
    Node* temp = new Node;
    temp->data = s;
    temp->next = nullptr;
    totalSong++;
    if (head == nullptr)
    {
        head = temp;
        currentSong = temp;
        tail = temp;
        currSong++;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        
    }
}
void PlayList::ShowAll() const 
{
    Node* current = head;
    int number = 0;
    while (current != nullptr) {
        std::cout << "No:" << number <<" " << current->data << std::endl;
        current = current->next;
        number++;
    }
}

void PlayList::Play(int num)
{
    /*currentsong = currentsong->next; if num == -1
    * currsong++;
   temp = head;
   currsong = num;
   for(int i < num){
   temp = temp.next
     }
     currentsong = temp
     
     
     */
    Node* temp = head;
    if (num == -1) {
        cout << currentSong->data << endl;
        currentSong = currentSong->next;
        currSong++;
    }
   
    else {
        currSong = num;
        for (int i = 0; i < num; i++) {
            temp = temp->next;
        }
        cout << currentSong->data << endl;
    }
    currentSong = temp;
   
}
 
bool PlayList::DeleteSong(const Song& s) 
{
    //recieve song and find the song s in playlist if found delete that node
    //if found() num--;
   
      //temp is used to freeing the memory
     Node* temp;

    //key found on the head node.
    //move to head node to the next and free the head.
    if (head->data == s)
    {
        temp = head;    //backup to free the memory
        head = (head)->next;
        free(temp);
        totalSong--;
        return true;
        
    }
    else
    {
        
        while (currentSong->next != NULL)
        {
            //if yes, we need to delete the current->next node
            if (currentSong->next->data == s)
            {
                temp = currentSong->next;
                //node will be disconnected from the linked list.
                currentSong->next = currentSong->next->next;
                free(temp);
                totalSong--;
                return true;
            }
            //Otherwise, move the current node and proceed
            else {
                currentSong = currentSong->next;
            }
            
        }
        cout << "Can't find the song" << endl;
        return false;
        
    }
}
void PlayList::ShowStatus() const   
{
    //cout totalsong 
    //for cout currsong
    cout << totalSong << " song(s), currently at song No. " << currSong << endl;
}
