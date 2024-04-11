#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	int Location = -1;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node* down = nullptr;
	Node* up = nullptr;
};

class Transport_Layer_optimization
{
private:
	Node* Metro;
	Node* Bus;
	Node* Walking;

	// Total number of current Locations 
	int mTotal;
	int bTotal;
	int wTotal;

public:

	Transport_Layer_optimization()
	{
		Metro = nullptr;
		Bus = nullptr;
		Walking = nullptr;

		mTotal = 0;
		bTotal = 0;
		wTotal = 0;
	}

	void addNode(int layer, int Location_id)
	{
		Node* temp;
		Node* tempPrev;
		Node* x;	// For parsing not concerned Nodes
		int count = 0, count2 = 0;
		bool skip = false;

		// Metro
		if (layer == 1)
		{
			// If there are no Nodes in the Metro Layer
			if (Metro == nullptr)
			{	
				mTotal++;

				Metro = new Node;
				Metro->Location = Location_id;
				Metro->next = nullptr;
				Metro->prev = nullptr;
				Metro->up = nullptr;

				// If there is no Node below in the Bus Layer
				if (Bus == nullptr)
					Metro->down = nullptr;
				else
				{
					Metro->down = Bus;
					Bus->up = Metro;
				}
			}

			else
			{
				temp = Metro;
				tempPrev = Metro;

				// If Metro Layer only has 1 Node
				if (temp->next == nullptr)
				{
					count = 2;

					// Add Empty Nodes till LocationID
					while (count != Location_id)
					{
						if (count == 1)
						{
							tempPrev->next = new Node;
							temp = tempPrev->next;
						}

						else
						{
							temp->next = new Node;
							tempPrev = temp;
							temp = temp->next;
						}

						mTotal++;

						temp->Location = -1;
						temp->up = nullptr;
						temp->next = nullptr;
						temp->prev = tempPrev;

						// Checking if there is a Node below current Node in Bus Layer
						if (bTotal < mTotal)
							temp->down = nullptr;
						else
						{
							x = Bus;

							for (int i = 1; i < mTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->down = nullptr;
							else
							{
								temp->down = x;
								x->up = temp;
							}
						}

						count++;
					}

					// Add Node at LocationID
					mTotal++;

					temp->next = new Node;
					tempPrev = temp;
					temp = temp->next;

					temp->Location = Location_id;
					temp->up = nullptr;
					temp->next = nullptr;
					temp->prev = tempPrev;

					// Checking if there is a Node below current Node in Bus Layer
					if (bTotal < mTotal)
						temp->down = nullptr;
					else
					{
						x = Bus;

						for (int i = 1; i < bTotal; i++)
							x = x->next;

						if (x->Location == -1)
							temp->down = nullptr;
						else
						{
							temp->down = x;
							x->up = temp;
						}
					}
				}

				// If Metro has more than 1 Nodes
				else
				{
					count2 = 1;

					// Reaching the last defined Location
					while (temp->next != nullptr)
					{
						count2++;
						tempPrev = temp;
						temp = temp->next;

						// If Location is currently -1
						if (count2 == Location_id)
						{
							temp->Location = Location_id;
							skip = true;
							break;
						}
					}
					
					if (skip == false)
					{
						count = mTotal + 1;

						// Add Empty Nodes till LocationID
						while (count != Location_id)
						{
							temp->next = new Node;
							tempPrev = temp;
							temp = temp->next;

							mTotal++;

							temp->Location = -1;
							temp->up = nullptr;
							temp->next = nullptr;
							temp->prev = tempPrev;

							// Checking if there is a Node below current Node in Bus Layer
							if (bTotal < mTotal)
								temp->down = nullptr;
							else
							{
								x = Bus;

								for (int i = 1; i < mTotal; i++)
									x = x->next;

								if (x->Location == -1)
									temp->down = nullptr;
								else
								{
									temp->down = x;
									x->up = temp;
								}
							}

							count++;
						}

						// Add Node at LocationID
						mTotal++;

						temp->next = new Node;
						tempPrev = temp;
						temp = temp->next;

						temp->Location = Location_id;
						temp->up = nullptr;
						temp->next = nullptr;
						temp->prev = tempPrev;

						// Checking if there is a Node below current Node in Bus Layer
						if (bTotal < mTotal)
							temp->down = nullptr;
						else
						{
							x = Bus;

							for (int i = 1; i < mTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->down = nullptr;
							else
							{
								temp->down = x;
								x->up = temp;
							}
						}
					}
				}
			}
		}
		
		// Bus
		if (layer == 2)
		{
			// If there are no Nodes in the Bus Layer
			if (Bus == nullptr)
			{
				bTotal++;

				Bus = new Node;
				Bus->Location = Location_id;
				Bus->next = nullptr;
				Bus->prev = nullptr;

				// If there is no Node below in the Walking Layer
				if (Walking == nullptr)
					Bus->down = nullptr;
				else
				{
					Bus->down = Walking;
					Walking->up = Bus;
				}

				// If there is no Node above in the Metro Layer
				if (Metro == nullptr)
					Bus->up = nullptr;
				else
				{
					Bus->up = Metro;
					Metro->down = Bus;
				}
			}

			else
			{
				temp = Bus;
				tempPrev = Bus;

				// If Bus Layer only has 1 Node
				if (temp->next == nullptr)
				{
					count = 2;

					// Add Empty Nodes till LocationID
					while (count != Location_id)
					{
						if (count == 1)
						{
							tempPrev->next = new Node;
							temp = tempPrev->next;
						}

						else
						{
							temp->next = new Node;
							tempPrev = temp;
							temp = temp->next;
						}

						bTotal++;

						temp->Location = -1;
						temp->next = nullptr;
						temp->prev = tempPrev;

						// Checking if there is a Node below in the Walking Layer
						if (wTotal < bTotal)
							temp->down = nullptr;
						else
						{
							x = Walking;

							for (int i = 1; i < bTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->down = nullptr;
							else
							{
								temp->down = x;
								x->up = temp;
							}
						}

						// Checking if there is a Node above in the Metro Layer
						if (mTotal < bTotal)
							temp->up = nullptr;
						else
						{
							x = Metro;

							for (int i = 1; i < bTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->up = nullptr;
							else
							{
								temp->up = x;
								x->down = temp;
							}
						}

						count++;
					}

					// Add Node at LocationID
					bTotal++;

					temp->next = new Node;
					tempPrev = temp;
					temp = temp->next;

					temp->Location = Location_id;
					temp->next = nullptr;
					temp->prev = tempPrev;

					// Checking if there is a Node above in the Metro Layer
					if (mTotal < bTotal)
						temp->up = nullptr;
					else
					{
						x = Metro;

						for (int i = 1; i < bTotal; i++)
							x = x->next;

						if (x->Location == -1)
							temp->up = nullptr;
						else
						{
							temp->up = x;
							x->down = temp;
						}
					}

					// Checking if there is a Node below current Node in the Walking Layer
					if (wTotal < bTotal)
						temp->down = nullptr;
					else
					{
						x = Walking;

						for (int i = 1; i < bTotal; i++)
							x = x->next;

						if (x->Location == -1)
							temp->down = nullptr;
						else
						{
							temp->down = x;
							x->up = temp;
						}
					}
				}

				// If Bus has more than 1 Nodes
				else
				{
					count2 = 1;

					// Reaching the last defined Location
					while (temp->next != nullptr)
					{
						count2++;
						tempPrev = temp;
						temp = temp->next;

						// If Location is currently -1
						if (count2 == Location_id)
						{
							temp->Location = Location_id;
							skip = true;
							break;
						}
					}

					if (skip == false)
					{
						count = bTotal + 1;

						// Add Empty Nodes till LocationID
						while (count != Location_id)
						{
							temp->next = new Node;
							tempPrev = temp;
							temp = temp->next;

							bTotal++;

							temp->Location = -1;
							temp->next = nullptr;
							temp->prev = tempPrev;

							// Checking if there is a Node above in the Metro Layer
							if (mTotal < bTotal)
								temp->up = nullptr;
							else
							{
								x = Metro;

								for (int i = 1; i < bTotal; i++)
									x = x->next;

								if (x->Location == -1)
									temp->up = nullptr;
								else
								{
									temp->up = x;
									x->down = temp;
								}
							}

							// Checking if there is a Node below current Node in the Walking Layer
							if (wTotal < bTotal)
								temp->down = nullptr;
							else
							{
								x = Walking;

								for (int i = 1; i < bTotal; i++)
									x = x->next;

								if (x->Location == -1)
									temp->down = nullptr;
								else
								{
									temp->down = x;
									x->up = temp;
								}
							}

							count++;
						}

						// Add Node at LocationID
						bTotal++;

						temp->next = new Node;
						tempPrev = temp;
						temp = temp->next;

						temp->Location = Location_id;
						temp->next = nullptr;
						temp->prev = tempPrev;

						// Checking if there is a Node below current Node in the Walking Layer
						if (wTotal < bTotal)
							temp->down = nullptr;
						else
						{
							x = Walking;

							for (int i = 1; i < bTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->down = nullptr;
							else
							{
								temp->down = x;
								x->up = temp;
							}
						}

						// Checking if there is a Node above in the Metro Layer
						if (mTotal < bTotal)
							temp->up = nullptr;
						else
						{
							x = Metro;

							for (int i = 1; i < bTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->up = nullptr;
							else
							{
								temp->up = x;
								x->down = temp;
							}
						}
					}
				}
			}
		}
		
		// Walking
		if (layer == 3)
		{
			// If there are no Nodes in the Walking Layer
			if (Walking == nullptr)
			{
				wTotal++;

				Walking = new Node;
				Walking->Location = Location_id;
				Walking->next = nullptr;
				Walking->prev = nullptr;
				Walking->down = nullptr;

				// If there is no Node above in the Bus Layer
				if (Bus == nullptr)
					Walking->up = nullptr;
				else
				{
					Walking->up = Bus;
					Bus->down = Walking;
				}
			}

			else
			{
				temp = Walking;
				tempPrev = Walking;

				// If Walking Layer only has 1 Node
				if (temp->next == nullptr)
				{
					count = 2;

					// Add Empty Nodes till LocationID
					while (count != Location_id)
					{
						if (count == 1)
						{
							tempPrev->next = new Node;
							temp = tempPrev->next;
						}

						else
						{
							temp->next = new Node;
							tempPrev = temp;
							temp = temp->next;
						}

						wTotal++;

						temp->Location = -1;
						temp->down = nullptr;
						temp->next = nullptr;
						temp->prev = tempPrev;

						// Checking if there is a Node above in the Bus Layer
						if (bTotal < wTotal)
							temp->down = nullptr;
						else
						{
							x = Bus;

							for (int i = 1; i < wTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->up = nullptr;
							else
							{
								temp->up = x;
								x->down = temp;
							}
						}

						count++;
					}

					// Add Node at LocationID
					wTotal++;

					temp->next = new Node;
					tempPrev = temp;
					temp = temp->next;

					temp->Location = Location_id;
					temp->down = nullptr;
					temp->next = nullptr;
					temp->prev = tempPrev;

					/// Checking if there is a Node above in the Bus Layer
					if (bTotal < wTotal)
						temp->down = nullptr;
					else
					{
						x = Bus;

						for (int i = 1; i < wTotal; i++)
							x = x->next;

						if (x->Location == -1)
							temp->up = nullptr;
						else
						{
							temp->up = x;
							x->down = temp;
						}
					}
				}

				// If Walking has more than 1 Nodes
				else
				{
					count2 = 1;

					// Reaching the last defined Location
					while (temp->next != nullptr)
					{
						count2++;
						tempPrev = temp;
						temp = temp->next;

						// If Location is currently -1
						if (count2 == Location_id)
						{
							temp->Location = Location_id;
							skip = true;
							break;
						}
					}

					if (skip == false)
					{
						count = wTotal + 1;

						// Add Empty Nodes till LocationID
						while (count != Location_id)
						{
							temp->next = new Node;
							tempPrev = temp;
							temp = temp->next;

							wTotal++;

							temp->Location = -1;
							temp->down = nullptr;
							temp->next = nullptr;
							temp->prev = tempPrev;

							// Checking if there is a Node below current Node in Bus Layer
							if (bTotal < wTotal)
								temp->up = nullptr;
							else
							{
								x = Bus;

								for (int i = 1; i < wTotal; i++)
									x = x->next;

								if (x->Location == -1)
									temp->up = nullptr;
								else
								{
									temp->up = x;
									x->down = temp;
								}
							}

							count++;
						}

						// Add Node at LocationID
						wTotal++;

						temp->next = new Node;
						tempPrev = temp;
						temp = temp->next;

						temp->Location = Location_id;
						temp->down = nullptr;
						temp->next = nullptr;
						temp->prev = tempPrev;

						// Checking if there is a Node below current Node in Bus Layer
						if (bTotal < wTotal)
							temp->up = nullptr;
						else
						{
							x = Bus;

							for (int i = 1; i < wTotal; i++)
								x = x->next;

							if (x->Location == -1)
								temp->up = nullptr;
							else
							{
								temp->up = x;
								x->down = temp;
							}
						}
					}
				}
			}
		}
	}

	void DeleteNode(int layer, int Location_id)
	{
		Node* temp;
		bool skip = false;

		// If Node does not Exist
		if ((layer == 1 && mTotal < Location_id) || (layer == 2 && bTotal < Location_id) || (layer == 3 && wTotal < Location_id))
		{
			cout << "\n\nLocation does not exist.\n\n";
			skip = true;
		}

		else
		{
			// Get to Node
			temp = Metro;

			if (layer == 2)
				temp = Bus;

			if (layer == 3)
				temp = Walking;

			for (int i = 1; i < Location_id; i++)
				temp = temp->next;

			// If Location is the last Node
			if (layer == 1 && temp->Location == mTotal)
			{
				temp->prev->next = nullptr;

				if (bTotal >= mTotal)
					temp->down->up = nullptr;

				delete temp;
				skip = true;
			}

			if (layer == 2 && temp->Location == bTotal)
			{
				temp->prev->next = nullptr;

				if (mTotal >= bTotal)
					temp->up->down = nullptr;

				if (wTotal >= bTotal)
					temp->down->up = nullptr;

				delete temp;
				skip = true;
			}

			if (layer == 3 && temp->Location == wTotal)
			{
				temp->prev->next = nullptr;

				if (bTotal >= wTotal)
					temp->up->down = nullptr;

				delete temp;
				skip = true;
			}

			// Check if location Exists
			if (skip == false)
			{
				if (temp->Location == -1)
					cout << "\n\nLocation does not exist.\n\n";
				else
					temp->Location = -1;
			}
		}
	}

	void ReadFile(string filename)
	{
		// Data read from file
		string x;	// int(x - '0') to convert to int	

		ifstream myFile;
		myFile.open(filename);

		// Reading n, m & q
		myFile >> x;
		int n = stoi(x);

		myFile >> x;
		int m = stoi(x);

		myFile >> x;
		int q = stoi(x);
		
		// Metro
		for (int i = 0; i < n; i++)
		{
			myFile >> x;
			addNode(1, stoi(x));
		}

		// Bus
		for (int i = 0; i < m; i++)
		{
			myFile >> x;
			addNode(2, stoi(x));
		}

		// Walking
		for (int i = 0; i < q; i++)
		{
			myFile >> x;
			addNode(3, stoi(x));
		}

		myFile.close();
	}

	string GetPath(int start, int end)
	{
		bool mStart = true, bStart = false, wStart = false;
		bool moveBack = false, moveDown = false, moveUp = false, moveNext = false, repeat = false;
		int layer = 1;
		Node* temp;
		string x = "";

		// Getting to start Location

		// Starting from Metro
		if (mTotal < start || mTotal == 0)
		{
			mStart = false;
			bStart = true;
		}

		else
		{
			temp = Metro;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			if (temp->Location == -1)
			{
				mStart = false;
				bStart = true;
			}
		}

		// Starting from Bus if cannot start from Metro
		if (bStart == true)
		{
			layer = 2;

			if ((bTotal < start || bTotal == 0))
			{
				bStart = false;
				wStart = true;
			}

			else
			{
				temp = Bus;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				if (temp->Location == -1)
				{
					bStart = false;
					wStart = true;
				}
			}
		}

		// Starting from Walking if cannot start from Metro & Bus
		if (wStart == true)
		{
			layer = 3;

			if ((wTotal < start || wTotal == 0))
				wStart = false;

			else
			{
				temp = Walking;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				if (temp->Location == -1)
					wStart = false;
			}
		}

		// If Node to start with DOES NOT EXIST
		if (mStart == false && bStart == false && wStart == false)
			cout << "\n\nStarting Location does not exist.\n\n";

		// If Node to start with EXISTS
		else if (start != end)
		{
			x += to_string(temp->Location) + "-" + to_string(layer);

			if (temp->next != nullptr)
				if (temp->next->Location != -1 && temp->next != nullptr)
					moveNext = true;
			
			if (temp->prev != nullptr)
				if (temp->prev->Location != -1)
					moveBack = true;

			if (temp->down != nullptr)
				if (temp->down->Location != -1)
					moveDown = true;

			if (temp->up != nullptr)
				if (temp->up->Location != -1 && temp->up != nullptr)
					moveUp = true;

			int i = 0;
			while (temp->Location != end)
			{
				i++;

				// If Starting Node is isolated
				if (temp->down == nullptr && temp->next == nullptr && temp->prev == nullptr && temp->up == nullptr)
				{
					cout << "\n\nStarting Node is isolated and there is no where to go.\n\n";
					break;
				}

				// If start < end
				if (start < end)
				{
					if (temp->up != nullptr && moveUp == true)
					{
						temp = temp->up;

						if (temp->Location == -1)
						{
							temp = temp->down;
							moveUp = false;
						}

						else
						{
							layer--;

							moveDown = true;
							moveNext = false;
							moveUp = false;
							moveBack = false;

							// If next Node exists
							if (temp->next != nullptr)
								if (temp->next->Location != -1)
								{
									moveDown = false;
									moveNext = true;
								}

							// If Node above exists
							if (temp->up != nullptr)
								if (temp->up->Location != -1)
								{
									moveDown = false;
									moveUp = true;
								}

							// If prev Node exists
							if (temp->prev != nullptr)
								if (temp->prev->Location != -1)
								{
									moveDown = false;
									moveBack = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}

					else if (temp->next != nullptr && moveNext == true)
					{
						temp = temp->next;

						if (temp->Location == -1)
						{
							temp = temp->prev;
							moveNext = false;
						}

						else
						{
							moveBack = true;
							moveNext = false;
							moveDown = false;
							moveUp = false;

							// If next Node exists
							if (temp->next != nullptr)
								if (temp->next->Location != -1)
								{
									moveBack = false;
									moveNext = true;
								}

							// If Node above exists
							if (temp->up != nullptr)
								if (temp->up->Location != -1)
								{
									moveBack = false;
									moveUp = true;
								}

							// If Node below exists
							if (temp->down != nullptr)
								if (temp->down->Location != -1)
								{
									moveBack = false;
									moveDown = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}

					else if (temp->down != nullptr && moveDown == true)
					{
						temp = temp->down;

						if (temp->Location == -1)
						{
							temp = temp->up;
							moveDown = false;
						}

						else
						{
							layer++;

							moveUp = true;
							moveNext = false;
							moveDown = false;
							moveBack = false;

							// If next Node exists
							if (temp->next != nullptr)
								if (temp->next->Location != -1)
								{
									moveUp = false;
									moveNext = true;
								}

							// If Node below exists
							if (temp->down != nullptr)
								if (temp->down->Location != -1)
								{
									moveUp = false;
									moveDown = true;
								}

							// If prev Node exists
							if (temp->prev != nullptr)
								if (temp->prev->Location != -1)
								{
									moveUp = false;
									moveBack = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}

					else if (moveBack == true)
					{
						repeat = true;
						temp = temp->prev;

						if (temp->Location == -1)
						{
							temp = temp->next;
							moveBack = false;
						}

						else
						{
							moveNext = true;
							moveBack = false;
							moveDown = false;
							moveUp = false;

							// If Node above exists
							if (temp->up != nullptr)
								if (temp->up->Location != -1)
								{
									moveNext = false;
									moveUp = true;
								}

							// If Node below exists
							if (temp->down != nullptr)
								if (temp->down->Location != -1)
								{
									moveNext = false;
									moveDown = true;
								}

							// If prev Node exists
							if (temp->prev != nullptr)
								if (temp->prev->Location != -1)
								{
									moveNext = false;
									moveBack = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}
				}

				// If start > end
				if (start > end)
				{
					if (temp->up != nullptr && moveUp == true)
					{
						temp = temp->up;

						if (temp->Location == -1)
						{
							temp = temp->down;
							moveUp = false;
						}

						else
						{
							layer--;

							moveDown = true;
							moveNext = false;
							moveUp = false;
							moveBack = false;

							// If prev Node exists
							if (temp->prev != nullptr)
								if (temp->prev->Location != -1)
								{
									moveDown = false;
									moveBack = true;
								}
							
							// If next Node exists
							if (temp->next != nullptr)
								if (temp->next->Location != -1)
								{
									moveDown = false;
									moveNext = true;
								}

							// If Node above exists
							if (temp->up != nullptr)
								if (temp->up->Location != -1)
								{
									moveDown = false;
									moveUp = true;
								}
							
							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}

					else if (temp->prev != nullptr && moveBack == true)
					{
						temp = temp->prev;

						if (temp->Location == -1)
						{
							temp = temp->next;
							moveBack = false;
						}

						else
						{
							moveNext = true;
							moveBack = false;
							moveDown = false;
							moveUp = false;

							// If Node above exists
							if (temp->up != nullptr)
								if (temp->up->Location != -1)
								{
									moveNext = false;
									moveUp = true;
								}

							// If Node below exists
							if (temp->down != nullptr)
								if (temp->down->Location != -1)
								{
									moveNext = false;
									moveDown = true;
								}

							// If prev Node exists
							if (temp->prev != nullptr)
								if (temp->prev->Location != -1)
								{
									moveNext = false;
									moveBack = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}

					else if (temp->down != nullptr && moveDown == true)
					{
						temp = temp->down;

						if (temp->Location == -1)
						{
							temp = temp->up;
							moveDown = false;
						}

						else
						{
							layer++;

							moveUp = true;
							moveNext = false;
							moveDown = false;
							moveBack = false;

							// If prev Node exists
							if (temp->prev != nullptr)
								if (temp->prev->Location != -1)
								{
									moveUp = false;
									moveBack = true;
								}

							// If Node below exists
							if (temp->down != nullptr)
								if (temp->down->Location != -1)
								{
									moveUp = false;
									moveDown = true;
								}

							// If next Node exists
							if (temp->next != nullptr)
								if (temp->next->Location != -1)
								{
									moveUp = false;
									moveNext = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}

					else if (moveNext == true)
					{
						repeat = true;
						temp = temp->next;

						if (temp->Location == -1)
						{
							temp = temp->prev;
							moveNext = false;
						}

						else
						{
							moveBack = true;
							moveNext = false;
							moveDown = false;
							moveUp = false;

							// If next Node exists
							if (temp->next != nullptr)
								if (temp->next->Location != -1)
								{
									moveBack = false;
									moveNext = true;
								}

							// If Node above exists
							if (temp->up != nullptr)
								if (temp->up->Location != -1)
								{
									moveBack = false;
									moveUp = true;
								}

							// If Node below exists
							if (temp->down != nullptr)
								if (temp->down->Location != -1)
								{
									moveBack = false;
									moveDown = true;
								}

							x += " -> " + to_string(temp->Location) + "-" + to_string(layer);
						}
					}
				}
			}
		}

		else
		{
			cout << "\n\nStart = End.\n\n";
			x += temp->Location + "-" + layer;
		}

		if (repeat == true)
			removeRepeaters(start, end, x);

		return x;
	}

	void removeRepeaters(int start, int end, string &x)
	{
		bool found = false;
		string temp = x, digit = "", digitChecked = "";
		char l1 = '^', l2 = '^';

		for (int i = 0; i < x.length() - 2; i++)
			if (x[i] >= '1' && x[i] <= '9')
			{
				digit = "";
				l1 = '^';
				digit += x[i];

				if (x[i + 1] == '-')
				// Search digit in x
				{
					l1 = x[i + 2];
					for (int j = i + 3; j < x.length() - 2; j++)
						if (x[j] >= '0' && x[j] <= '9')
						{
							digitChecked = "";
							l2 = '^';
							digitChecked += x[j];
							l2 = x[j + 2];

							if (x[j + 1] == '-' && digitChecked == digit && l1 == l2)
							{
								for (int k = i + 3; k < j + 3; k++)
									temp[k] = '^';

								found = true;
								break;
							}
						}

					if (found == true)
						break;
				}
			}
			
		x = "";

		for (int i = 0; i < temp.length(); i++)
			if (temp[i] != '^')
				x += temp[i];
	}

	void print()
	{
		cout << "\n\n";
		Node* temp = Metro;

		for (int i = 0; i < mTotal; i++)
		{
			cout << temp->Location << " ";
			temp = temp->next;
		}

		cout << "\n";
		temp = Bus;

		for (int i = 0; i < bTotal; i++)
		{
			cout << temp->Location << " ";
			temp = temp->next;
		}

		cout << "\n";
		temp = Walking;

		for (int i = 0; i < wTotal; i++)
		{
			cout << temp->Location << " ";
			temp = temp->next;
		}

		cout << "\n\n" << mTotal << " " << bTotal << " " << wTotal << "\n\n";
	}
};

class Transport_Cost_Calculator
{
private:
	Node* Metro;
	Node* Bus;
	Node* Walking;

	// Total number of current Locations 
	int mTotal;
	int bTotal;
	int wTotal;

public:

	Transport_Cost_Calculator()
	{
		Metro = nullptr;
		Bus = nullptr;
		Walking = nullptr;

		mTotal = 0;
		bTotal = 0;
		wTotal = 0;
	}

	void addNode(int layer, int cost)
	{
		Node* temp;
		Node* tempPrev;
		int count = 0, count2 = 0;
		bool skip = false;

		// Metro
		if (layer == 1)
		{
			// If there are no Nodes in the Metro Layer
			if (Metro == nullptr)
			{
				mTotal = 1;

				Metro = new Node;
				Metro->Location = cost;
				Metro->next = nullptr;
				Metro->prev = nullptr;
				Metro->up = nullptr;

				// If there is no Node below in the Bus Layer
				if (Bus == nullptr)
					Metro->down = nullptr;
				else
				{
					Metro->down = Bus;
					Bus->up = Metro;
				}
			}

			// If there is only one Node
			else if (mTotal == 1)
			{
				mTotal = 2;
				temp = Metro;
				temp->next = new Node;
				temp = temp->next;
				temp->Location = cost;
				temp->prev = Metro;
				temp->up = nullptr;
				temp->next = nullptr;

				// If there is no Node below in the Bus Layer
				if (bTotal < 2)
					temp->down = nullptr;
				else
				{
					temp->down = Bus->next;
					Bus->next->up = temp;
				}
			}

			// If there are more than 2 nodes
			else
			{
				temp = Metro;

				for (int i = 1; i < mTotal; i++)
					temp = temp->next;

				temp->next = new Node;
				tempPrev = temp;
				temp = temp->next;
				temp->Location = cost;
				temp->up = nullptr;
				temp->next = nullptr;
				temp->prev = tempPrev;

				mTotal++;

				// If there is no Node below in the Bus Layer
				if (bTotal < mTotal)
					temp->down = nullptr;
				else
				{
					tempPrev = Bus;

					for (int i = 1; i < mTotal; i++)
						tempPrev = tempPrev->next;

					temp->down = tempPrev;
					tempPrev->up = temp;
				}
			}
		}

		// Bus
		if (layer == 2)
		{
			// If there are no Nodes in the Bus Layer
			if (Bus == nullptr)
			{
				bTotal = 1;

				Bus = new Node;
				Bus->Location = cost;
				Bus->next = nullptr;
				Bus->prev = nullptr;

				// If there is no Node above in the Metro Layer
				if (Metro == nullptr)
					Bus->up = nullptr;
				else
				{
					Metro->down = Bus;
					Bus->up = Metro;
				}

				// If there is no Node below in the Walking Layer
				if (Walking == nullptr)
					Bus->down = nullptr;
				else
				{
					Bus->down = Walking;
					Walking->up = Bus;
				}
			}

			// If there is only one Node
			else if (bTotal == 1)
			{
				bTotal = 2;
				temp = Bus;
				temp->next = new Node;
				temp = temp->next;
				temp->Location = cost;
				temp->prev = Bus;
				temp->up = nullptr;
				temp->next = nullptr;

				// If there is no Node above in the Metro Layer
				if (Metro == nullptr)
					Bus->up = nullptr;
				else
				{
					Metro->down = Bus;
					Bus->up = Metro;
				}

				// If there is no Node below in the Walking Layer
				if (Walking == nullptr)
					Bus->down = nullptr;
				else
				{
					Bus->down = Walking;
					Walking->up = Bus;
				}
			}

			// If there are more than 2 nodes
			else
			{
				temp = Bus;

				for (int i = 1; i < bTotal; i++)
					temp = temp->next;

				temp->next = new Node;
				tempPrev = temp;
				temp = temp->next;
				temp->Location = cost;
				temp->up = nullptr;
				temp->next = nullptr;
				temp->prev = tempPrev;

				bTotal++;

				// If there is no Node above in the Metro Layer
				if (mTotal < bTotal)
					temp->up = nullptr;
				else
				{
					tempPrev = Metro;

					for (int i = 1; i < bTotal; i++)
						tempPrev = tempPrev->next;

					temp->up = tempPrev;
					tempPrev->down = temp;
				}

				// If there is no Node below in the Walking Layer
				if (wTotal < bTotal)
					temp->down = nullptr;
				else
				{
					tempPrev = Walking;

					for (int i = 1; i < bTotal; i++)
						tempPrev = tempPrev->next;

					temp->down = tempPrev;
					tempPrev->up = temp;
				}
			}
		}

		// Walking
		if (layer == 3)
		{
			// If there are no Nodes in the Walking Layer
			if (Walking == nullptr)
			{
				wTotal = 1;

				Walking = new Node;
				Walking->Location = cost;
				Walking->next = nullptr;
				Walking->prev = nullptr;
				Walking->up = nullptr;

				// If there is no Node above in the Bus Layer
				if (Bus == nullptr)
					Walking->up = nullptr;
				else
				{
					Walking->up = Bus;
					Bus->down = Walking;
				}
			}

			// If there is only one Node
			else if (wTotal == 1)
			{
				wTotal = 2;
				temp = Walking;
				temp->next = new Node;
				temp = temp->next;
				temp->Location = cost;
				temp->prev = Walking;
				temp->up = nullptr;
				temp->next = nullptr;

				// If there is no Node above in the Bus Layer
				if (Bus == nullptr)
					Walking->up = nullptr;
				else
				{
					Walking->up = Bus;
					Bus->down = Walking;
				}
			}

			// If there are more than 2 nodes
			else
			{
				temp = Walking;

				for (int i = 1; i < wTotal; i++)
					temp = temp->next;

				temp->next = new Node;
				tempPrev = temp;
				temp = temp->next;
				temp->Location = cost;
				temp->up = nullptr;
				temp->next = nullptr;
				temp->prev = tempPrev;

				wTotal++;

				// If there is no Node above in the Bus Layer
				if (bTotal < wTotal)
					temp->down = nullptr;
				else
				{
					tempPrev = Bus;

					for (int i = 1; i < wTotal; i++)
						tempPrev = tempPrev->next;

					temp->up = tempPrev;
					tempPrev->down = temp;
				}
			}
		}
	}

	void DeleteNode(int layer, int Location_id)
	{
		Node* temp;
		bool skip = false;

		// If Node does not Exist
		if ((layer == 1 && mTotal < Location_id) || (layer == 2 && bTotal < Location_id) || (layer == 3 && wTotal < Location_id))
		{
			cout << "\n\nLocation does not exist.\n\n";
			skip = true;
		}

		else
		{
			// Get to Node
			temp = Metro;

			if (layer == 2)
				temp = Bus;

			if (layer == 3)
				temp = Walking;

			for (int i = 1; i < Location_id; i++)
				temp = temp->next;

			// If Location is the last Node
			if (layer == 1 && temp->Location == mTotal)
			{
				temp->prev->next = nullptr;

				if (bTotal >= mTotal)
					temp->down->up = nullptr;

				delete temp;
				skip = true;
			}

			if (layer == 2 && temp->Location == bTotal)
			{
				temp->prev->next = nullptr;

				if (mTotal >= bTotal)
					temp->up->down = nullptr;

				if (wTotal >= bTotal)
					temp->down->up = nullptr;

				delete temp;
				skip = true;
			}

			if (layer == 3 && temp->Location == wTotal)
			{
				temp->prev->next = nullptr;

				if (bTotal >= wTotal)
					temp->up->down = nullptr;

				delete temp;
				skip = true;
			}

			// Check if location Exists
			if (skip == false)
			{
				if (temp->Location == -1)
					cout << "\n\nLocation does not exist.\n\n";
				else
					temp->Location = -1;
			}
		}
	}

	void ReadFile(string filename)
	{
		// Data read from file
		string x;

		ifstream myFile;
		myFile.open(filename);

		// Reading n, m & q
		myFile >> x;
		int n = stoi(x) - 1;

		// Metro
		for (int i = 0; i < n; i++)
		{
			myFile >> x;
			addNode(1, stoi(x));
		}

		// Bus
		for (int i = 0; i < n; i++)
		{
			myFile >> x;
			addNode(2, stoi(x));
		}

		// Walking
		for (int i = 0; i < n; i++)
		{
			myFile >> x;
			addNode(3, stoi(x));
		}

		myFile.close();

		cout << "\n\n" << x << "\n\n";
	}

	int GetMinCost(int start, int end)
	{ 
		Node* temp;
		Node* checker;
		int mCost = 0, bCost = 0, wCost = 0, count = 1, layer = 1, cost = 0, startCost = 0, startLayer = 1, jump1Cost = 11111110, jump1layer = 1, jump1Node = 1, jump1CurCost = 1;
		bool notUp = false, notDown = false;

		if (start == end)
			return 0;

		// Get to the best Start Node
		if (start == 1)
		{
			mCost = Metro->Location;
			bCost = Bus->Location;
			wCost = Walking->Location;

			if (mCost == bCost && mCost < wCost)
			{
				cost = mCost;
				mCost = Metro->next->Location;
				bCost = Bus->next->Location;

				if (mCost < bCost)
				{
					temp = Metro->next->next;
					cost += mCost;
				}

				else
				{
					temp = Bus->next->next;
					layer = 2;
					cost += bCost;
				}

				count = 3;
			}
			
			else if (mCost == wCost && mCost < bCost)
			{
				cost = mCost;
				mCost = Metro->next->Location;
				wCost = Walking->next->Location;

				if (mCost < wCost)
				{
					temp = Metro->next->next;
					cost += mCost;
				}

				else
				{
					temp = Walking->next->next;
					layer = 3;
					cost += wCost;
				}

				count = 3;
			}
			
			else if (wCost == bCost && wCost < mCost)
			{
				cost = wCost;
				wCost = Walking->next->Location;
				bCost = Bus->next->Location;

				if (bCost < wCost)
				{
					temp = Bus->next->next;
					layer = 2;
				}

				else
				{
					temp = Walking->next->next;
					layer = 3;
				}

				count = 3;
			}

			else if (mCost == wCost && mCost == bCost)
			{
				cost = mCost;
				mCost = Metro->next->Location;
				wCost = Walking->next->Location;
				bCost = Bus->next->Location;

				if (mCost < wCost && mCost < bCost)
				{
					temp = Metro->next->next;
					cost += mCost;
				}

				else if (bCost < wCost && bCost < mCost)
				{
					temp = Bus->next->next;
					cost += bCost;
					layer = 2;
				}

				else
				{
					temp = Walking->next->next;
					cost += wCost;
					layer = 3;
				}

				count = 3;
			}
			
			else if (mCost < wCost && mCost <= bCost)
			{
				temp = Metro->next;
				cost += mCost;
				count++;
			}

			else if (bCost < wCost && bCost <= mCost)
			{
				temp = Bus->next;
				layer = 2;
				cost += bCost;
				count++;
			}

			else if (wCost < mCost && wCost <= bCost)
			{
				temp = Walking->next;
				layer = 3;
				cost += wCost;
				count++;
			}

			startCost = cost;
			startLayer = layer;
		}

		else if (start < 0)
			return 0;

		else if (start < end)
		{
			temp = Metro;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			mCost = temp->Location;

			temp = Bus;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			bCost = temp->Location;

			temp = Walking;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			wCost = temp->Location;

			if (mCost < wCost && mCost <= bCost)
			{
				temp = Metro;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				cost += mCost;
				count = start;
			}

			else if (bCost < wCost && bCost <= mCost)
			{
				temp = Bus;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				layer = 2;
				cost += bCost;
				count = start;
			}

			else if (wCost < mCost && wCost <= bCost)
			{
				temp = Walking;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				layer = 3;
				cost += wCost;
				count = start;
			}

			startCost = cost;
			startLayer = layer;
		}

		else if (start > end)
		{
			temp = Metro;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			mCost = temp->prev->Location;

			temp = Bus;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			bCost = temp->prev->Location;

			temp = Walking;

			for (int i = 1; i < start; i++)
				temp = temp->next;

			wCost = temp->prev->Location;

			if (mCost < wCost && mCost <= bCost)
			{
				temp = Metro;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				cost += mCost;
				count = start;
			}

			else if (bCost < wCost && bCost <= mCost)
			{
				temp = Bus;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				layer = 2;
				cost += bCost;
				count = start;
			}

			else if (wCost < mCost && wCost <= bCost)
			{
				temp = Walking;

				for (int i = 1; i < start; i++)
					temp = temp->next;

				layer = 3;
				cost += wCost;
				count = start;
			}

			startCost = cost;
			startLayer = layer;
			}

		if (count != mTotal)
			while (count != end)
			{
				//cout << "C : " << cost << endl;
				cout << count << "-" << layer << " -> ";
				//cout << "J! : " << jump1Cost << endl;
				
				if (start < end)
				{
					if (layer == 1)
					{
						mCost = temp->Location;
						bCost = 5;

						if (mCost <= bCost || notDown == true)
						{
							cost += mCost;
							temp = temp->next;
							count++;
							notDown = false;
							notUp = false;
						}

						else
						{
							temp = temp->down;
							layer = 2;
							cost += 5;
							notUp = true;
						}
					}
				
					else if (layer == 2)
					{
						mCost = 5;
						bCost = temp->Location;
						wCost = 5;

						if (bCost <= mCost && bCost <= wCost || (notUp == true && notDown == true))
						{
							cost += bCost;
							temp = temp->next;
							count++;
							notDown = false;
							notUp = false;
						}

						else if (mCost <= bCost && mCost <= wCost && notUp == false)
						{
							cost += 5;
							temp = temp->up;
							layer = 1;
							notDown = true;
						}
					
						else if (notDown == false)
						{
							cost += 5;
							temp = temp->down;
							layer = 3; 
							notUp = true;
						}
					}
				
					else if (layer == 3)
					{
						bCost = 5;
						wCost = temp->Location;

						if (wCost <= bCost || notUp == true)
						{
							cost += wCost;
							temp = temp->next;
							count++;
							notDown = false;
							notUp = false;
						}

						else if (notUp == false)
						{
							cost += 5;
							temp = temp->up;
							layer = 2;
							notDown = true;
						}
					}
				}

				if (start > end)
				{
					if (layer == 1)
					{
						mCost = temp->prev->Location;
						bCost = 5;

						if (mCost <= bCost || notDown == true)
						{
							cost += mCost;
							temp = temp->prev;
							count--;
							notDown = false;
							notUp = false;
						}

						else
						{
							temp = temp->down;
							layer = 2;
							cost += 5;
							notUp = true;
						}
					}

					else if (layer == 2)
					{
						mCost = 5;
						bCost = temp->prev->Location;
						wCost = 5;

						if (bCost <= mCost && bCost <= wCost || (notUp == true && notDown == true))
						{
							cost += bCost;
							temp = temp->prev;
							count--;
							notDown = false;
							notUp = false;
						}

						else if (mCost <= bCost && mCost <= wCost && notUp == false)
						{
							cost += 5;
							temp = temp->up;
							layer = 1;
							notDown = true;
						}

						else if (notDown == false)
						{
							cost += 5;
							temp = temp->down;
							layer = 3;
							notUp = true;
						}
					}

					else if (layer == 3)
					{
						bCost = 5;
						wCost = temp->prev->Location;

						if (wCost <= bCost || notUp == true)
						{
							cost += wCost;
							temp = temp->prev;
							count--;
							notDown = false;
							notUp = false;
							jump1Cost = temp->prev->Location;
							jump1layer = layer;
							jump1Node = count;
							jump1CurCost = cost;
						}

						else if (notUp == false)
						{
							cost += 5;
							temp = temp->up;
							layer = 2;
							notDown = true;
						}
					}
				}

				if (jump1Cost < (cost - jump1CurCost))
				{
					cost -= jump1CurCost;
					cost += jump1Cost;

					temp = Walking;

					for (int z = 1; z < jump1Node - 1; z++)
						temp = temp->next;

					count++;
					layer = 3;
					jump1Cost = 10000;
				}

				if (count == start - 1 && layer == startLayer + 2)
				{
					checker = Bus;

					for (int z = 0; z < start - 1; z++)
						checker = checker->next;

					if (checker->Location < cost)
						cost = checker->Location;
				}
			}

			if (start > end)
				cost -= startCost;

			//cout << "C : " << cost << endl;
			cout << count << "-" << layer << endl << endl;


		return cost;
	}

	void print()
	{
		cout << "\n\n";
		Node* temp = Metro;

		for (int i = 0; i < mTotal; i++)
		{
			cout << temp->Location << " ";
			temp = temp->next;
		}

		cout << "\n";
		temp = Bus;

		for (int i = 0; i < bTotal; i++)
		{
			cout << temp->Location << " ";
			temp = temp->next;
		}

		cout << "\n";
		temp = Walking;

		for (int i = 0; i < wTotal; i++)
		{
			cout << temp->Location << " ";
			temp = temp->next;
		}

		cout << "\n\n" << mTotal << " " << bTotal << " " << wTotal << "\n\n";
	}
};