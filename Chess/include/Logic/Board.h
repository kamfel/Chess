#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

class Piece;
class King;
class GraphicsHolder;

enum COLOUR;

class Board : 
	public sf::Sprite
{
private:

	//Vector containing all the pieces that are on board
	std::vector<Piece*> m_pieces;

	//Vector containing all captured pieces
	std::vector<Piece*> m_captured_pieces;

	//White king
	King* m_white_king;

	//Black king
	King* m_black_king;

	//Chosen piece
	Piece* m_chosen_piece;

	//Container for easy access to textures
	GraphicsHolder* m_textures;

	//Attacked fields; every bit represents a field
	long long m_attacked_fields;

protected:

	///Returns piece that is on field with coordinates pos
	///param pos: field coordinates
	///return value: piece if field is not empty
	///return value: nullptr if field is empty
	Piece* GetPieceOnField(const sf::Vector2i& pos) const;

public:

	Board();
	virtual ~Board();

	bool CheckForStalemate(COLOUR colour);
	bool CheckForCheck(COLOUR colour);
	bool CheckForMate(COLOUR colour);

	///Returns field information
	///param pos: field coordinates
	///return value: std::pair where first is true when field is empty and second is color of piece on the field
	std::pair<bool, COLOUR> GetFieldInfo(const sf::Vector2i& pos) const;

	void CalculateAttackedFields(COLOUR colour);

	void UnchoosePiece();

	bool ChoosePiece(const sf::Vector2i& pos, COLOUR player_colour);

	bool IsPieceChosen() const { return m_chosen_piece; }

	bool TryMove(const sf::Vector2i& pos, COLOUR player_colour);

	bool IsFieldAttacked(const sf::Vector2i& pos, COLOUR player_colour) const;

	///Sets pieces on starting position
	void SetPiecesOnStartingPos();

	///Loads textures and keeps reference to GraphicsHolder object
	///param gh: object containing
	void SetTexture(GraphicsHolder& gh);

	///Draws board and pieces to target window
	///param window: target window
	void DrawBoardAndPieces(sf::RenderWindow& window);

	static sf::Vector2i ConvertBoardXYtoDisplayXY(const sf::Vector2i& boardXY);
	static sf::Vector2i ConvertDisplayXYtoBoardXY(const sf::Vector2i& displayXY);
	
	static bool AreDisplayXYWithinBoard(const sf::Vector2i& displayXY);
};

