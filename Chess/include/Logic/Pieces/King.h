#pragma once
#include "Piece.h"

/*! \brief Class representing king piece
*
*
*/
class King :
	public Piece
{
private:

	bool m_is_checked = false; ///< Is king checked

	bool m_castling_left = true; ///< Is caastling to the left possible

	bool m_castling_right = true; ///< is castling to the right possible

public:
	/*! \brief Constructor
	*
	* Creates a king with colour = colour and position = pos
	* \param colour Colour of the king
	* \param pos Position of the king
	* \param gh Reference to class containing textures (see GraphicsHolder)
	*/
	King(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~King();

	/*! \brief Generates moves for king
	*
	* \sa Piece::GeneratePossibleMoves(const Board & board)
	*/
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
	
	/*! \brief Checks if king is checked
	*
	* \return true if king is checked
	*/
	bool IsChecked() { return m_is_checked; };

	/*! \brief Checks the king
	*
	* 
	*/
	void Check() { m_is_checked = true; }

	/*! \brief Unchecks the king
	*
	*
	*/
	void Uncheck() { m_is_checked = false; }

	/*! \brief Sets castling to the left possibility
	*
	*
	*/
	void CastlingIsPossibleForLeftRook(bool left);

	/*! \brief Sets castling to the right possibility
	*
	*
	*/
	void CastlingIsPossibleForRightRook(bool right);
};

