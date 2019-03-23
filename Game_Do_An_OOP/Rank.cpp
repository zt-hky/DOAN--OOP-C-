#include "Rank.h"



void CRank::Push(std::string _strName, int _score)
{
	int i;
	for (i = 0; i < m_iN; i++)
	{
		if (_score > m_iScore[i])
			break;
	}

	m_strName.push_back("");
	m_iScore.push_back(0);

	for(int j = m_iN; j > i; j--)
	{
		m_strName[j] = m_strName[j - 1];
		m_iScore[j] = m_iScore[j - 1];
	}
	m_strName[i] = _strName;
	m_iScore[i] = _score;
	m_iN++;
}

bool CRank::ReadFile()
{
	int ReadIntTmp;
	char ReadStrTmp[c_MaxLenghtName + 1];
	std::string tmp;
	m_strName.clear();
	m_iScore.clear();
	m_iN = 0;
	std::ifstream ifs(c_FileScore, std::fstream::binary | std::fstream::beg);
	if (ifs.fail())return false;

	ifs.read((char*)&m_iN, _INT_SIZE);

	for(int i = 0; i < m_iN;i++)
	{
		ifs.read((char*)&ReadIntTmp, _INT_SIZE);
		ifs.read((char*)&ReadStrTmp, c_MaxLenghtName + 1);
		ReadStrTmp[c_MaxLenghtName] = '\0';
		tmp.assign(ReadStrTmp);
		m_iScore.push_back(ReadIntTmp);
		m_strName.push_back(tmp);

	}
	ifs.close();
	return true;
}

void CRank::WriteFile()
{
	std::ofstream ofs(c_FileScore, std::fstream::binary | std::fstream::beg);
	ofs.clear();
	ofs.write((char*)&m_iN, _INT_SIZE);

	for (int i = 0; i < m_iN; i++)
	{
		ofs.write((char*)&m_iScore[i], _INT_SIZE);
		ofs.write((char*)m_strName[i].c_str(), c_MaxLenghtName + 1);
	}
	ofs.close();
}

void CRank::Out()
{
	for(int i = 0 ; i < m_iN; i++)
	{
		std::cout << std::endl << m_iScore[i] << "\t" << m_strName[i] ;
	}
}

int CRank::GetScore(int i)
{
	return m_iScore[i];
}

std::string CRank::GetName(int i)
{
	return std::string(m_strName[i]);
}

int CRank::GetN()
{
	return m_iN;
}

CRank::CRank()
{
}


CRank::~CRank()
{
}
