#pragma once
#include "Piece.h"

/*! \brief Class representing rook piece
*
*
*/
class Rook :
	public Piece
{
public:

	/*! \brief Constructor
	*
	* Creates a rook with colour = colour and position = pos
	* \param colour Colour of the rook
	* \param pos Position of the rook
	* \param gh Reference to class containing textures (see GraphicsHolder)
	*/
	Rook(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Rook();
	
	/*! \brief Generates moves for pawn
	*
	* \sa Piece::GeneratePossibleMoves(const Board & board)
	*/
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
};

