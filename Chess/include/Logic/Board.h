#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

class Piece;
class King;
class GraphicsHolder;

enum COLOUR;

/*! \brief Class representing the board
*
* 
*/
class Board : 
	public sf::Sprite
{
private:

	std::vector<Piece*> m_pieces; ///< Vector containing all the pieces that are on board

	std::vector<Piece*> m_captured_pieces; 	///<Vector containing all captured pieces

	King* m_white_king;	///< White king

	King* m_black_king; ///< Black king

	Piece* m_chosen_piece; ///< Piece chosen by player

	GraphicsHolder* m_textures; ///<Container for easy access to textures

	long long m_attacked_fields; 	///< Attacked fields; every bit represents a field

protected:

	/*! \brief Get field on certain position
	*
	* \param pos Position on board
	* \return Pointer to piece if field is not empty; nullptr otherwise
	*/
	Piece* GetPieceOnField(const sf::Vector2i& pos) const;

public:

	Board();
	virtual ~Board();

	/*! \brief Check for stalemate
	*
	* \param colour Colour of player for which to check for stalemate
	* \return true if there is a stalemate
	*/
	bool CheckForStalemate(COLOUR colour);

	/*! \brief Check for check
	*
	* \param colour Colour of player for which to check for check
	* \return true if there is a check
	*/
	bool CheckForCheck(COLOUR colour);

	/*! \brief Check for checkmate
	*
	* \param colour Colour of player for which to check for checkmate
	* \return true if there is a checkmate
	*/
	bool CheckForMate(COLOUR colour);

	/*! \brief Get information of the field
	*
	* \param pos Position of the field
	* \return std::pair where first element is a boolean true if field is empty and false otherwise;
	*  second element is colour of the piece occupying the field or NONE otherwise
	*/
	std::pair<bool, COLOUR> GetFieldInfo(const sf::Vector2i& pos) const;

	/*! \brief Calculates attacked fields
	*
	* Calculates which fields are attacked by opponent of player with colour specified in parameter
	* \param colour Colour of the player
	*/
	void CalculateAttackedFields(COLOUR colour);

	/*! \brief Unchooses and unhighlights piece
	*
	*/
	void UnchoosePiece();

	/*! \brief Chooses and highlights piece
	*
	* \param pos Position of the piece
	* \param player_colour Colour of player choosing the piece
	* \return true if piece was chosen succesfully; false otherwise
	*/
	bool ChoosePiece(const sf::Vector2i& pos, COLOUR player_colour);

	/*! \brief Was a piece chosen by player earlier
	*
	* \return true if piece was chosen; false otherwise
	*/
	bool IsPieceChosen() const { return m_chosen_piece; }

	/*! \brief Try to make a move
	*
	* Analyzes if piece which was chosen earlier can make a move to position pos
	* \param pos Position to move to
	* \param player_colour Colour of the player trying to make a move
	* \return true if move was made succesfully; false otherwise
	*/
	bool TryMove(const sf::Vector2i& pos, COLOUR player_colour);

	/*! \brief Check if field is attacked by opponent
	*
	* \param pos Position to check
	* \param player_colour Colour of the player checking
	* \return true if field is attacked; false otherwise
	*/
	bool IsFieldAttacked(const sf::Vector2i& pos, COLOUR player_colour) const;

	/*! \brief Sets pieces on starting position
	*
	* Besides setting pieces on starting position, also discards previous game state
	*/
	void SetPiecesOnStartingPos();

	/*! \brief Loads textures
	*
	* Loads textures and keeps reference to GraphicsHolder object
	* \param gh Class containing textures (see GraphicsHolder)
	*/
	void SetTexture(GraphicsHolder& gh);

	/*! \brief Draw board and pieces to target window
	*
	* \param window Window to draw to
	*/
	void DrawBoardAndPieces(sf::RenderWindow& window);

	/*! \brief Converts coordinates
	*
	* Converts coordinates based on sizes defined in Definitions.h
	* \sa Definitions.h
	* \param boardXY Board coordinates
	* \return Display coordinates
	*/
	static sf::Vector2i ConvertBoardXYtoDisplayXY(const sf::Vector2i& boardXY);

	/*! \brief Converts coordinates
	*
	* Converts coordinates based on sizes defined in Definitions.h
	* \sa Definitions.h
	* \param displayXY Display coordinates
	* \return Board coordinates
	*/
	static sf::Vector2i ConvertDisplayXYtoBoardXY(const sf::Vector2i& displayXY);
	
	/*! \brief Checks coordinates
	*
	* Checks if coordinates are within the board on the display based on sizes defined in Definitions.h
	* \sa Definitions.h
	* \param displayXY Display coordinates
	* \return true if coordinates are within board on the screen; false otherwise
	*/
	static bool AreDisplayXYWithinBoard(const sf::Vector2i& displayXY);
};

