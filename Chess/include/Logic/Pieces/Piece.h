#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include <vector>

class Board;
class GraphicsHolder;

/*! \brief Enum representing colour of the pieces
*
*/
enum COLOUR { NONE, BLACK, WHITE };

/*! \brief Class representing piece; must be implemented
*
* Provides basic functionality for every piece
*/
class Piece : 
	public sf::Sprite
{
protected:

	static sf::RectangleShape m_highlight_background; ///< Shape for highlighting

	
	sf::Vector2i m_pos; ///< Current position of the piece on the board

	std::vector<sf::Vector2i> m_possible_moves; ///< Possible moves for the piece; might not be actual

	bool m_was_piece_moved = false; ///< Was piece moved at all in the game

	COLOUR m_colour; ///< Colour of the piece

	bool m_highlighted; ///< Was the piece clicked and highlighted

	/*! \brief Checks if move to pos is valid
	*
	* \param pos Position to move to
	* \return true if move is valid
	*/
	bool IsMoveValid(const sf::Vector2i pos) const;

public:
	/*! \brief Constructor
	*
	* Creates a piece with colour = colour and position = pos
	* \param colour Colour of the piece
	* \param pos Position of the piece
	*/
	Piece(COLOUR colour, const sf::Vector2i& pos);
	virtual ~Piece();

	/*! \brief Moves piece to pos
	*
	* \param pos New piece coordinates
	* \return true if move was succesful
	*/
	bool Move(const sf::Vector2i& pos);

	/*! \brief Generates possible moves for piece
	* 
	* Must be implemented by classes inheriting from Piece
	* \param board Reference to board
	* \return Vector containing all possible moves for piece
	*/
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board& board) = 0;

	/*! \brief Returns possible moves for piece
	*
	* Should be called only when moves are calculated
	* No point in calling GeneratePossibleMoves when moves are already calculated
	* \return Vector containing all possible moves for piece
	*/
	const std::vector<sf::Vector2i>& GetMoves() { return m_possible_moves; }

	/*! \brief Highlights piece
	*
	*/
	void Highlight();

	/*! \brief Unhighlights piece
	*
	*/
	void Unhighlight();

	/*! \brief Get current position of the piece
	*
	* \return Current position of the piece
	*/
	const sf::Vector2i GetPos() const { return m_pos; }

	/*! \brief Set flag that piece was moved
	*
	*/
	void Moved() { m_was_piece_moved = true; }

	/*! \brief Check if piece is at certain position
	*
	* \param pos Position to check
	* \return true if piece is on postion pos
	*/
	bool IsAtPos(const sf::Vector2i& pos) { return pos == m_pos; }

	/*! \brief Get colour of the piece
	*
	* \return Colour of the piece
	*/
	COLOUR GetColour() const { return m_colour; }

	/*! \brief Check if piece was moved since start of the game
	*
	* \return true if piece was moved
	*/
	bool WasPieceMoved() const { return m_was_piece_moved; }


	/*! \brief Sets piece position
	*
	* Should not be called for performing moves
	* \param pos New piece position
	*/
	void SetPos(const sf::Vector2i& pos) { m_pos = pos; }

	/*! \brief Draws piece
	*
	* Replaces SFML's draw function
	* For more information on parameters see SFML documentation
	* \param target Target to draw to
	* \param states Current render states
	*/
	void Draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
