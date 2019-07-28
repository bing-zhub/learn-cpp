sort(data.begin(), data.end(), cmp);
  map<string, vector<record>> custom;
  for(int i = 1; i < n; i++) {
    if(data[i].name == data[i-1].name && data[i - 1].status == 1 && data[i].status == 0){
      // on-line / off-line 匹配
      custom[data[i - 1].name].push_back(data[i - 1]);
      custom[data[i].name].push_back(data[i]);
    }
  }
  for(auto c: custom){
    vector<record> temp = c.second;
    cout << c.first;
    printf(" %02d\n", temp[0].month);
    double total = 0.0;
    for(int i = 1; i < temp.size(); i += 2){
      double t = billFromZero(temp[i], rate) - billFromZero(temp[i-1], rate);
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i-1].day, temp[i-1].hour, temp[i-1].minute, temp[i-1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i-1].time, t);
      total += t;
    }
    printf("Total amount: $%.2f\n", total);
  }