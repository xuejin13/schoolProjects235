// Name: Xuejin Gao (the beast)
// Class: CSCI 235
// Professor: Tiziana Ligorio
// Description: Song Interface

#ifndef SONG_H
#define SONG_H
// using namespace std;
#include <vector>
#include <string>

// template<class ItemType>
class Song{
    public:
    	Song();
		Song(const std::string& title, const std::string& author, const std::string& album);
		void setTitle(std::string title);  //"set" in setTitle here means "give a value" and has nothing
                                   // to do with the Set class. Similarly for setAuthor and setAlbum
		void setAuthor(std::string author);
		void setAlbum(std::string album);
		std::string getTitle() const;
		std::string getAuthor() const;
		std::string getAlbum() const;
		friend bool operator==(const Song& lhs, const Song& rhs);
    private:
    	std::string title_;
		std::string author_;
		std::string album_;
};


#endif /* SET_INTERFACE_H_ */

