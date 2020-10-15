class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		queue<int> keys;
		for (int i = 0; i < rooms[0].size(); ++i) {
			keys.push(rooms[0][i]);
		}

		bool openRooms[1005];
		memset(openRooms, 0, sizeof(openRooms));
		while (!keys.empty()) {
			int roomToOpen = keys.front();
			keys.pop();
			if (openRooms[roomToOpen] == 1) continue;
			openRooms[roomToOpen] = 1;
			for (int i = 0; i < rooms[roomToOpen].size(); ++i) {
				keys.push(rooms[roomToOpen][i]);
			}
		}


		for (int i = 0; i < rooms.size(); ++i) {
			if (openRooms[i] == 0) {
				return 0;
			}
		}

		return 1;
	}
};