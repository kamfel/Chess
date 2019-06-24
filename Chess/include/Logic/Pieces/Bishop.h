#pragma once
#include "Piece.h"

/*! \brief Class representing bishop piece
*
*
*/
class Bishop :
	public Piece
{
public:
	/*! \brief Constructor
	*
	* Creates a bishop with colour = colour and position = pos
	* \param colour Colour of the bishop
	* \param pos Position of the bishop
	* \param gh Reference to class containing textures (see GraphicsHolder)
	*/
	Bishop(COLOUR colour, const sf::Vector2i& pos, const GraphicsHolder& gh);
	virtual ~Bishop();

	/*! \brief Generates moves for bishop
	*
	* \sa Piece::GeneratePossibleMoves(const Board & board)
	*/
	virtual const std::vector<sf::Vector2i>& GeneratePossibleMoves(const Board & board) override;

};

 