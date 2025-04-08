#include "tune.h"

#include <sstream>
#include <vector>

// Tuner taken from Obsidian
// Thx gabe

std::vector<EngineParam *> tuningParams;

void registerParam(EngineParam *param)
{
  tuningParams.push_back(param);
}

EngineParam *findParam(std::string name)
{
  for (int i = 0; i < static_cast<int>(tuningParams.size()); i++)
  {
    if (tuningParams.at(i)->name == name)
    {
      return tuningParams.at(i);
    }
  }
  return nullptr;
}

std::string paramsToUci()
{
  std::ostringstream ss;

  for (int i = 0; i < static_cast<int>(tuningParams.size()); i++)
  {
    EngineParam *p = tuningParams.at(i);

    ss << "option name " << p->name << " type spin default " << p->value << " min -999999999 max 999999999\n";
  }

  return ss.str();
}

std::string paramsToSpsaInput()
{
  std::ostringstream ss;

  for (int i = 0; i < static_cast<int>(tuningParams.size()); i++)
  {
    EngineParam *p = tuningParams.at(i);

    ss << p->name
       << ", " << "int"
       << ", " << double(p->value)
       << ", " << double(p->min)
       << ", " << double(p->max)
       << ", " << std::max(0.5, double(p->max - p->min) / 20.0)
       << ", " << 0.002
       << "\n";
  }

  return ss.str();
}


DEFINE_PARAM_B(seePawn, 168, 70, 280);
DEFINE_PARAM_B(seeKnight, 215, 143, 560);
DEFINE_PARAM_B(seeBishop, 405, 170, 700);
DEFINE_PARAM_B(seeRook, 564, 270, 1100);
DEFINE_PARAM_B(seeQueen, 741, 520, 2090);

int SEE_PIECE_VALUES[7] = {seePawn, seeKnight, seeBishop, seeRook, seeQueen, 0, 0};

DEFINE_PARAM_B(piecePawn, 77, 35, 140);
DEFINE_PARAM_B(pieceKnight, 285, 125, 516);
DEFINE_PARAM_B(pieceBishop, 287, 105, 440);
DEFINE_PARAM_B(pieceRook, 321, 238, 952);
DEFINE_PARAM_B(pieceQueen, 764, 285, 1138);

int PIECE_VALUES[7] = {piecePawn, pieceKnight, pieceBishop, pieceRook, pieceQueen, 15000, 0};