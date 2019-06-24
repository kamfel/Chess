#pragma once
#include "Piece.h"

/*! \brief Class representing knight piece
*
*
*/
class Knight :
	public Piece
{
public:
	/*! \brief Constructor
	*
	* Creates a knight with colour = colour and position = pos
	* \param colour Colour of the knight
	* \param pos Position of the knight
	* \param gh Reference to class containing textures (see GraphicsHolder)
	*/
	Knight(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Knight();

	/*! \brief Generates moves for knight
	*
	* \sa Piece::GeneratePossibleMoves(const Board & board)
	*/
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;
};

