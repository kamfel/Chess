#pragma once
#include "Piece.h"

/*! \brief Class representing king piece
*
*
*/
class Pawn :
	public Piece
{
private:

	bool m_aupassant_left_possible = false; ///< true if pawn can capture au passant to the left

	bool m_aupassant_right_possible = false; ///< true if pawn can capture au passant to the right

	bool m_aupassant_vulnerable = false; ///< true if pawn can be captured au passant
public:
	/*! \brief Constructor
	*
	* Creates a pawn with colour = colour and position = pos
	* \param colour Colour of the pawn
	* \param pos Position of the pawn
	* \param gh Reference to class containing textures (see GraphicsHolder)
	*/
	Pawn(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Pawn();

	/*! \brief Generates moves for pawn
	*
	* \sa Piece::GeneratePossibleMoves(const Board & board)
	*/
	const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board& board) override;

	/*! \brief Sets capture au passant flags for pawn
	*
	* \param left au passant capturing to the left
	* \param right au passant capturing to the right
	*/
	void AupassantIsPossible(bool left, bool right);


	/*! \brief Can piece be captured au passant
	*
	* \return true if piece can be captured au passant
	*/
	bool IsAupassantVulnerable() { return m_aupassant_vulnerable; }

	/*! \brief Set flag for au passant capturing
	*
	* \param t Can pawn be captured au passant
	*/
	void SetAupassantVulnerable(bool t) { m_aupassant_vulnerable = t; }
};


