# Sales-Analysis-Master

This project's objective is to integrate file structure concepts of C++ with Data Mining's well known Apriori principle. This integrated system is applied on the transaction data of small scale businesses. The entire project works with simply the terminal and text editor in Linux systems. 

The input design is as follows:
1. A text file that contains transaction data for a user-defined x period of time(measured in number of days). This file is a pre-requisite before executing this file.
2. A command line input is taken from the user regarding the inventory of their business for the same x period of time. The inventory details needed here are the item id, item name and a 0/1 value for whether the specified item is a need (0) or a want (1). 
3. A min support value which signifies the the minimum Support value to be used to draw association rules from the given itemsets(transaction data).

The Output design is the inference drawn from the given itemsets in the form of association rules and an explanation of what the inference means. This is displayed on the terminal and is stored in a text file. 

The process is menu driven. There are 4 options given to the user:
1. Create an inventory list as input.
2. Modify the inventory list.
3. View recent inference drawn. 
4. Draw new inference. 

The third option validates the need for leaving the min support value upto the user. So they can experiment with various values and compare. 

The transaction file needs to adhere to a specific format:

item_id\titem_id\item_id\titem_id
item_id\titem_id\item_id\titem_id\titem_id
item_id\titem_id\item_id\titem_id\titem_id\titem_id
item_id\titem_id\item_id\titem_iditem_id\titem_id\item_id\titem_id

where, each line represents a single unit of time(1 hour, 1 day, 1 week, etc.,)
and the number of lines represent the transaction period x and each item_id in each line represents the item_id of the item sold during that single unit of time, for eg:
1st line represents all items sold on that day. 

