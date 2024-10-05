#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

//Location Class
class Location {
    int row;
    int col;
public:
    Location()
    {
        row = 0;
        col = 0;
    }
    Location(int r, int c)
    {
        row = r;
        col = c;
    }
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    void setRow(int r)
    {
        row = r;
    }
    void setCol(int c)
    {
        col = c;
    }
    friend ostream& operator<<(ostream& o, const Location temp);
};
ostream& operator<<(ostream& o, const Location temp)
{
    o << temp.row << " " << temp.col << endl;;
    return o;
}

//Stack Code
template <class T>
class stack
{
    struct stackNode
    {
        T data;
        stackNode* Next;
    };
    stackNode* Head;
public:
    stack();
    void push(T);
    void pop();
    T top();
    bool isEmpty();
    void display_stack();
};

template <class T>
stack<T>::stack()
{
    Head = NULL;
}

template <class T>
void stack<T>::push(T y)
{
    stackNode* newnode = new stackNode;
    newnode->data = y;
    newnode->Next = NULL;
    if (Head != NULL)
    {
        stackNode* currentnode = Head;
        while (currentnode->Next != NULL)
        {
            currentnode = currentnode->Next;
        }
        currentnode->Next = newnode;

    }
    else
    {
        Head = newnode;
    }

}

template <class T>
void stack<T>::pop()
{

    if (Head)
    {

        stackNode* temp = Head;
        Head = Head->Next;
        delete temp;

    }
}

template <class T>
T stack<T>::top()
{
    T element;
    if (Head)
    {
        element = Head->data;
        return element;
    }
}

template <class T>
bool stack<T>::isEmpty()
{
    return Head == nullptr;
}

template <class T>
void stack<T>::display_stack()
{
    stackNode* currentnode = Head;
    cout << "Stack ->";
    while (currentnode != NULL)
    {
        cout << currentnode->data << "\t";
        currentnode = currentnode->Next;
    }
    cout << endl;
    delete currentnode;
}


// Queue code

template <class q>
class queue
{
    struct Node
    {
        q data;
        Node* Next;
    };
    Node* Head = NULL;
public:
    queue() { Head = NULL; }
    ~queue() { }
    void push(q);
    void pop();
    q top();
    bool isempty();
    bool clear_queue();
    void display_list();
};

template <class q>
void queue<q>::push(q x)
{
    Node* newnode = new Node;
    newnode->data = x;
    newnode->Next = NULL;
    if (Head != NULL)
    {
        Node* currentnode = Head;
        while (currentnode->Next != NULL)
        {
            currentnode = currentnode->Next;
        }
        currentnode->Next = newnode;
        //cout << "Element " << x << " is pushed into the queue\n";

    }
    else
    {
        Head = newnode;
        //cout << "Element " << x << " is pushed into the queue\n";
    }
}

template <class q>
void queue<q>::pop()
{
    q element;
    if (Head)
    {
        element = Head->data;

        Node* temp = Head;
        Head = Head->Next;
        delete temp;

        //cout << "Element " << element << " is popped out from the queue\n";
    }
}

template <class q>
q queue<q>::top()
{
    q element;
    if (Head)
    {
        element = Head->data;
        return element;
    }
}

template <class q>
bool queue<q>::isempty()
{
    return Head == nullptr;
}

template <class q>
bool queue<q>::clear_queue()
{
    if (Head)
    {
        while (Head != NULL)
            pop();

        //cout << "Queue is cleared now\n";
        return 1;
    }
    else
    {
        //cout << "Queue is already cleared\n";
        return 0;
    }
}

template <class q>
void queue<q>::display_list()
{
    Node* currentnode = Head;
    while (currentnode != NULL)
    {
        cout << currentnode->data;
        currentnode = currentnode->Next;
    }
    delete currentnode;
}

// Array class
class Image {
    int** arr;
    int row;
    int col;
    int countR;
    int countC;
public:
    Image()
    {
        arr = NULL;
        row = col = countR = countC = 0;
    }
    Image(const Image& obj)
    {
        this->row = obj.row;
        this->col = obj.col;
        setSize(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = obj.arr[i][j];
            }
        }
        //_arr = new int[_size];

        //for (int i = 0; i < _size; i++)
            //*_arr[i] = *obj._arr[i];
    }

    void setSize(int r, int c)
    {
        arr = new int* [r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new int[c];
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                arr[i][j] = 255;
            }
        }
        row = r;
        col = c;
    }
    void insert(int value)
    {

        if (row != countR)
        {
            if (value == 32 || value == 0)
            {
                cout << value << " ";
                arr[countR][countC] = 0;
                countC++;
            }
            else
            {
                arr[countR][countC] = 255;
                countC++;
            }
            if (countC < (col))
            {
                countC = 0;
                countR++;
            }
        }
    }
    void setRow(int r)
    {
        row = r;
    }
    void setCol(int c)
    {
        col = c;
    }
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    void save(string n)
    {
        string line1 = "P5\n";
        line1 += "#" + n + "\n" + "#converted PNM file\n" + to_string(col) + " " + to_string(row) + "\n" + "255\n";

        ofstream object(n);
        object << line1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == 0)
                {
                    object << (char(0));
                }
                else if (arr[i][j] == 255)
                {
                    object << char(255);
                }
            }
        }
        object.close();

    }
    void read(string name)
    {
        int word = 0;
        ifstream object;
        int count = 0;
        string data;
        object.open(name, ios::in);
        if (object.is_open())
        {
            while (!object.eof())
            {
                object >> data;
                if (count == 5)
                    this->col = (stoi(data));
                if (count == 6)
                    this->row = (stoi(data));
                if (count == 7)
                    break;
                count++;
            }
        }
        else
            cout << "File not found" << endl;
        object.close();
        //creating array according to the size
        setSize(row, col);
        //reading data into the array
        char c;
        object.open(name, ios::in);
        for (int i = 0; i < 5; i++) //skipping first four lines
            getline(object, data);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                object.get(c);
                if ((int(c)) == 0 || (int(c)) == 32)
                {
                    arr[i][j] = 0;
                }
                else
                    arr[i][j] = 255;
            }
        }



        /* while (!object.eof())
         {
             object.get(c);
             insert(int(c));
         }*/
        object.close();

    }
    void displayImage()
    {
        int j;
        int i;
        for (i = 0; i < row; i++)
        {
            cout << i << " = ";
            for (j = 0; j < col; j++)
            {
                //cout << arr[i][j];
                if (arr[i][j] == 0)
                {
                    cout << ".";
                }
                else
                    cout << "*";
            }
            cout << " " << j << endl;
        }
    }
    int getPixel(int r, int c)
    {
        if ((r >= 0 && r < row) && (c >= 0 && c < col))
            return arr[r][c];
        return -1;
    }
    void setPixel(int r, int c, int val)
    {
        if ((r >= 0 && r < row) && (c >= 0 && c < col))
            arr[r][c] = val;
    }


    //Q1 a part
    double mean()
    {
        long int sum = 0;
        double average = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                sum += arr[i][j];

        average = sum / double(row * col);

        cout << "Mean Pixels    = " << average << endl;
        return average;
    }
    //Q1 b part
    void countPixels()
    {
        int white = 0;
        int black = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == 0)
                {
                    black += 1;
                }
                else
                    white += 1;

            }
        }
        cout << "Black Pixels    = " << black << endl;
        cout << "White Pixels    = " << white << endl;

    }
    //Q1 c part
    void avgBlack()
    {
        int black = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == 0)
                {
                    black += 1;
                }
            }
        }
        cout << "Avg Black Pixels    = " << (black / (row)) << endl;

    }
    //Q1 d part
    void convertNegative()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == 0)
                    arr[i][j] = 255;
                else
                    arr[i][j] = 0;
            }
        }
    }

};

//cluster through queue

void connectedQueue(Image image, int r, int c)
{
    Image newImage;
    newImage.setRow(image.getRow());
    newImage.setCol(image.getCol());
    if ((r < image.getRow() && r >= 0) && (c >= 0 && c < image.getCol()))
    {
        newImage.setSize(image.getRow(), image.getCol());
        queue<Location> temp;
        Location loc(r, c);
        int value = image.getPixel(r, c);
        int notValue = 255 * (value != 255);
        temp.push(loc);
        while (!temp.isempty())
        {
            // check 8 neighbour pixels, 1 current pixel (9 total pixels)
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    //making sure it doesnot go beyond the columns or rows
                    if ((temp.top().getRow() + i >= image.getRow() || temp.top().getRow() + i < 0) || (temp.top().getCol() + j < 0 || temp.top().getCol() + j >= image.getCol()))
                        continue;
                    if (image.getPixel(temp.top().getRow() + i, temp.top().getCol() + j) == value)
                    {
                        bool middlePixel = (i == 0 && j == 0);
                        if (!middlePixel)
                        {
                            loc.setRow(temp.top().getRow() + i);
                            loc.setCol(temp.top().getCol() + j);
                            temp.push(loc);
                        }
                        //setting my current image value to opposite factor to avoid including this in queue again
                        image.setPixel(temp.top().getRow() + i, temp.top().getCol() + j, notValue);
                    }
                }
            }
            newImage.setPixel(temp.top().getRow(), temp.top().getCol(), 0);
            temp.pop();
        }
        //newImage.displayImage();
        //image.displayImage();
        newImage.save("connectedQueue.PGM");
    }

}

//cluster through stack
void connectedStack(Image image, int r, int c)
{
    Image newImage;
    newImage.setRow(image.getRow());
    newImage.setCol(image.getCol());
    if ((r < image.getRow() && r >= 0) && (c >= 0 && c < image.getCol()))
    {
        newImage.setSize(image.getRow(), image.getCol());
        stack<Location> temp;
        stack<Location> reverse;
        Location loc(r, c);
        int value = image.getPixel(r, c);
        int notValue = 255 * (value != 255);

        temp.push(loc);

        while (!temp.isEmpty())
        {
            // check 8 neighbour pixels, 1 current pixel (9 total pixels)
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    //making sure it doesnot go beyond the columns or rows
                    if ((temp.top().getRow() + i >= image.getRow() || temp.top().getRow() + i < 0) || (temp.top().getCol() + j < 0 || temp.top().getCol() + j >= image.getCol()))
                    {
                        continue;
                    }
                    if (image.getPixel(temp.top().getRow() + i, temp.top().getCol() + j) == value)
                    {
                        bool middlePixel = (i == 0 && j == 0);
                        if (!middlePixel)
                        {
                            loc.setRow(temp.top().getRow() + i);
                            loc.setCol(temp.top().getCol() + j);
                            temp.push(loc);
                        }
                        //setting my current image value to opposite factor to avoid including this in queue again
                        image.setPixel(temp.top().getRow() + i, temp.top().getCol() + j, notValue);
                    }
                }
            }
            newImage.setPixel(temp.top().getRow(), temp.top().getCol(), 0);
            temp.pop();
        }
        //newImage.displayImage();
        //image.displayImage();
        newImage.save("connectedStack.PGM");
    }

}

void display_menu()
{
    cout << "\n1- to display the solution of (Question 1)\n";
    cout << "2- to display the solution of (Question 2)\n";
    cout << "3- to display the solution of (Question 3)\n";
    cout << "4- to exit the program\n";
}
void display_q1Menu()
{
    cout << "\n1- To display the mean";
    cout << "\n2- To display the White and Black Pixels";
    cout << "\n3- To display the Avg Black Pixels in Row";
    cout << "\n4- To convert it into Negative Image";
    cout << "\n5- To Perform all the option above";
    cout << "\n6- To Terminate this";
    cout << "\nEnter Choice: ";

}

string operationsTime()
{
    struct tm t;
    time_t curr_time;
    curr_time = time(NULL);
    localtime_s(&t, &curr_time);
    string timee = (to_string(t.tm_hour) + ':' + to_string(t.tm_min) + ':' + to_string(t.tm_sec));
    return timee;
}

string fileNameTime()
{
    struct tm t;
    time_t curr_time;
    curr_time = time(NULL);
    localtime_s(&t, &curr_time);
    string timee = ("log_"+to_string(t.tm_year + 1990) + to_string(t.tm_mon + 1) + to_string(t.tm_mday) + to_string(t.tm_hour) + to_string(t.tm_min) + to_string(t.tm_sec) + ".txt");
    return timee;
}


int main()
{
    string name = "D:\\University\\Semester 3\\DS Theory\\Assignment Module 1\\Images\\cattle-9.PGM";
    string data;
    int choice = 0;
    bool invalidChoice = false;
    int choice2 = 0;
    int r, c;
    Image image;
    image.read(name);
    Image secondImage(image);
    string logData = "";
    fstream ofile(fileNameTime(), ios::out);

    while (choice != 4)
    {
        system("CLS");
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            logData += "\nQuestion 1 is Selected " + operationsTime();
            logData += "\n-----------------------------------------------------------------------------------------";
            while (choice2 != 6)
            {
                display_q1Menu();
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    system("CLS");
                    logData += "\n----Q1 Mean Function is Called. " + operationsTime();
                    image.mean();
                    break;
                case 2:
                    logData += "\n----Q1 White And Black Pixels Function is Called. " + operationsTime();
                    system("CLS");
                    image.countPixels();
                    break;
                case 3:
                    logData += "\n----Q1 Avg Black Pixels in Row Function is Called. " + operationsTime();
                    system("CLS");
                    image.avgBlack();
                    break;
                case 4:
                    logData += "\n----Q1 Image is Converted into Negative. " + operationsTime();
                    system("CLS");
                    image.convertNegative();
                    image.save("negative.pgm");
                    image.convertNegative();
                    cout << "\nImage is Successfully Converted and saved into Negative.pgm Format ";
                    break;
                case 5:
                    logData += "\n----Q1 All Functions are Called. " + operationsTime();
                    system("CLS");
                    image.mean();
                    image.countPixels();
                    image.avgBlack();
                    image.convertNegative();
                    image.save("negative.pgm");
                    image.convertNegative();
                    break;
                case 6:
                    logData += "\n----Q1 Question 1 is terminated. " + operationsTime();
                    break;
                default:
                    logData += "\n----Q1 Worng input. " + operationsTime();
                    cout << "\nWrong Input. ";
                    system("Pause");
                    system("CLS");
                    break;
                }
            }
            break;
        case 2:
            logData += "\n-----------------------------------------------------------------------------------------";
            logData += "\nQuestion 2 is Selected " + operationsTime();
            while (!invalidChoice)
            {
                cout << "Enter Row: ";
                cin >> r;
                cout << "Enter Col: ";
                cin >> c;
                if (r < 0 || r >= image.getRow() || c < 0 || c >= image.getCol())
                {
                    invalidChoice = false;
                    cout << "\nInvalid Choice";
                    logData += "\n----Q2 Invalid Row and Col. " + operationsTime();
                    system("Pause");
                }
                else
                    invalidChoice = true;
                logData += "\n----Q2 Row = " + to_string(r) + " Col = " + to_string(c) + " " + operationsTime();
            }

            connectedQueue(image, r, c);
            cout << "Image is saved as a connectedQueue.pgm\n";
            logData += "\n----Q2 Image is saved as a connectedQueue.pgm " + operationsTime();
            logData += "\n----Q2 Question 3 is terminated. " + operationsTime();
            system("Pause");
            break;
        case 3:
            logData += "\n-----------------------------------------------------------------------------------------";
            logData += "\nQuestion 3 is Selected " + operationsTime();
            invalidChoice = false;
            while (!invalidChoice)
            {
                cout << "Enter Row: ";
                cin >> r;
                cout << "Enter Col: ";
                cin >> c;
                if (r < 0 || r >= image.getRow() || c < 0 || c >= image.getCol())
                {
                    invalidChoice = false;
                    cout << "\nInvalid Choice";
                    logData += "\n----Q3 Invalid Row and Col. " + operationsTime();
                    system("Pause");
                }
                else
                {
                    invalidChoice = true;
                    logData += "\n----Q3 Row = " + to_string(r) + " Col = " + to_string(c) + " " + operationsTime();
                }
            }
            connectedStack(image, r, c);
            cout << "Image is saved as a connectedStack.pgm\n";
            logData += "\n----Q3 Image is saved as a connectedStack.pgm " + operationsTime();
            logData += "\n----Q3 Question 3 is terminated. " + operationsTime();
            system("Pause");
            break;
        case 4:
            cout << "You have successfully exited the program\n";
            break;
        default:
            cout << "Wrong Input\n";
            cout << "Enter to go back\n";
            cin.ignore();
        }
    }
    ofile << logData;
    ofile.close();

    return 0;
}
