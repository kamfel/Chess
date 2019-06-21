#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include <vector>

class Board;
class GraphicsHolder;

enum COLOUR { NONE, BLACK, WHITE };

class Piece : 
	public sf::Sprite
{
protected:

	//Shape for highlighting
	static sf::RectangleShape m_highlight_background;

	//Current position of the piece on the board
	sf::Vector2i m_pos;

	//Possible moves for the piece; might not be actual
	std::vector<sf::Vector2i> m_possible_moves;

	bool m_was_piece_moved = false;

	//Colour of the piece
	COLOUR m_colour;

	//Was the piece clicked and highlighted
	bool m_highlighted;

	bool IsMoveValid(const sf::Vector2i pos) const;

public:

	Piece(COLOUR color, const sf::Vector2i& pos);
	virtual ~Piece();

	bool Move(const sf::Vector2i& pos);
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board& board) = 0;
	const std::vector<sf::Vector2i>& GetMoves() { return m_possible_moves; }

	void Highlight();
	void Unhighlight();

	const sf::Vector2i GetPos() const { return m_pos; }

	void Moved() { m_was_piece_moved = true; }
	bool IsAtPos(const sf::Vector2i& pos) { return pos == m_pos; }
	COLOUR GetColour() const { return m_colour; }
	bool WasPieceMoved() const { return m_was_piece_moved; }

	void SetPos(const sf::Vector2i& pos) { m_pos = pos; }

	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
