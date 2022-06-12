#include "GameManager.h"

Game_Manager::Game_Manager()
{
	string playerName;
	cout << "Halo^^ Selamat datang di permainan Sudoku" << endl;
	cout << "Coba masukkan nama kamu deh:" << endl;
	cin >> playerName;
	player.setName(playerName);
	cout << "Hayyy " << playerName << "~~~" << endl << "Pilih menu ya! " << endl;

	int choose;
	bool condition = true;
	cout << "1. New Game" << endl << "2. Load Game" << endl;

	// Main Menu
	while (condition)
	{
		cout << "Nomer berapa yang kamu pilih nih? : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			play();
			condition = false;
			break;
		case 2:
			load();
			condition = false;
			break;
		case 3:
			quit();
			condition = false;
			break;
		default:
			cout << "Salah nulis Option ya? Coba lagi deh" << endl;
			break;
		}
	}
}

void Game_Manager::fillCell(int row, int col, int num)
{
	// create new command
	Commands* fill{};
	fill = new Command_Fill(&board, row, col, num);

	// Execute command
	fill->execute();

	// push command
	undo.pushCommand(fill);
}

void Game_Manager::deleteCell(int row, int col)
{
	int temp = board.getNum(row, col);
	Commands* remove{};
	remove = new Command_Delete(&board, row, col, temp);

	remove->execute();

	undo.pushCommand(remove);
}

bool Game_Manager::checkWin()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board.isValid(i, j, board.getNum(i, j)))
				return true;
		}
	}
	return false;
}

void Game_Manager::undoMove()
{
	Commands* a{};
	a = undo.popCommand();
	a->undo();
	redo.pushCommand(a);
}

void Game_Manager::redoMove()
{
	cout << "Redo Move" << endl;
	Commands* x{};
	x = redo.popCommand();
	x->execute();
}

void Game_Manager::quit()
{
	cout << "Exiting...." << endl;
	exit;
}

void Game_Manager::play()
{
	cout << "Memulai permainan hohoho..." << endl;
	move();
}

void Game_Manager::move()
{
	board.printBoard();
	bool condition = true;
	int opt;
	while (condition)
	{
		cout << "1. Isi papan" << endl;
		cout << "2. Hapus angka" << endl;
		cout << "3. Undo" << endl;
		cout << "4. Redo" << endl;
		cout << "5. Save" << endl;
		cout << "Nomer berapa yang kamu pilih nih? : ";

		cin >> opt;
		switch (opt)
		{
		case 1:
			// Fill
			int row, col, num;
			cout << "Masukin posisi dan angka yang mau kamu ganti ya!" << endl;
			cout << "Kolom>> ";
			cin >> row; 
			cout << "Baris>> "; 
			cin >> col; 
			cout << "Angka>> "; 
			cin >> num;
			fillCell(row, col, num);
			condition = false;
			break;

		case 2:
			// Delete
			int delRow, delCol;
			cout << "Masukin posisi papan yang ingin dihapus (x y) " << endl;
			cin >> delRow; cin >> delCol;
			deleteCell(delRow, delCol);
			condition = false;
			break;
		case 3:
			// Undo
			undoMove();
			condition = false;
			break;
		case 4:
			// Redo
			redoMove();
			condition = false;
			break;
		case 5:
			// Save
			save();
			condition = false;
			break;
		case 6:
			// Quit
			cout << "Quit" << endl;
			condition = false;
			exit(1);
			break;
		default:
			cout << "Salah nulis Option ya? Coba lagi deh" << endl;
			break;
		}
	}
}

void Game_Manager::save()
{
	fstream out;
	string filename;
	int temp, opt;
	bool condition = true;

	while (condition)
	{
		// Choose save file
		cout << "Pilih file untuk menyimpan progress mainmu ya^^ " << endl;
		cout << "1. Save File 1" << endl;
		cout << "2. Save File 2" << endl;
		cout << "3. Save File 3" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1:
			filename = "file1.txt";
			break;
		case 2:
			filename = "file2.txt";
			break;
		case 3:
			filename = "file3.txt";
			break;
		default:
			cout << "Save file doesn't exist" << endl;
			break;
		}

		if (out)
		{
			char ynOpt = ' ';
			cout << "Do you want to overwrite this save file?" << endl;
			cin >> ynOpt;
			if (ynOpt == 'Y' || ynOpt == 'y')
			{
				out.open(filename, fstream::out);
				condition = false;
			}
		}
		else
			out.open(filename, fstream::out);
	}

	// Program save board data
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp = board.getNum(i, j);
			out << temp << " ";
		}
		cout << endl;
	}
	out.close();
}

void Game_Manager::load()
{
	fstream in;
	string filename;
	int temp, opt;
	bool condition = true;

	while (condition)
	{
		// choose file slot
		cout << "Pilih file mana yang ingin kamu lanjutin nih^^" << endl;
		cout << "1. Save File 1" << endl;
		cout << "2. Save File 2" << endl;
		cout << "3. Save File 3" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1:
			filename = "file1.txt";
			break;
		case 2:
			filename = "file2.txt";
			break;
		case 3:
			filename = "file3.txt";
			break;
		default:
			cout << "Save file doesn't exist" << endl;
			break;
		}

		in.open(filename, fstream::in);
		if (in)	// if file exist
		{
			condition = false;
		}
		else
		{
			cout << "Save file doesn't exist" << endl;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			in >> temp;
			fillCell(i, j, temp);
		}
	}
	in.close();
	play();
}

int main()
{
	Game_Manager GM;

	while (!GM.checkWin())
	{
		GM.move();
		cout << GM.checkWin() << endl;
	}
	cout << "Waahh!! Hebat sekali kamu menang!!!" << endl;

	return 0;
}