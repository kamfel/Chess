#pragma once
#include "Piece.h"

/*! \brief Class representing queen piece
*
*
*/
class Queen :
	public Piece
{
public:
	/*! \brief Constructor
	*
	* Creates a queen with colour = colour and position = pos
	* \param colour Colour of the queen
	* \param pos Position of the queen
	* \param gh Reference to class containing textures (see GraphicsHolder)
	*/
	Queen(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Queen();

	/*! \brief Generates moves for pawn
	*
	* \sa Piece::GeneratePossibleMoves(const Board & board)
	*/
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
};

