typedef int listItemType;
struct listNode;
typedef listNode* ptrType;
class listClass
{
private:
	int Size;
	ptrType Head;
	ptrType PtrTo(int Position)const;
public:
	listClass();
	listClass(const listClass& L);
	~listClass();
	bool ListIsEmpty()const;
	int ListLength()const;
	void ListInsert(int NewPosition,listItemType NewItem,bool& Success);
	void ListDelete(int Position,bool& Success);
	void ListRetrieve(int Position, listItemType& DataItem, bool& Success)const;
};