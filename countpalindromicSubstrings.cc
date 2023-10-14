


int countPalindromicSubstrings(string str){

    int count = 0;

    for(int i = 0; i < str.size(); i++){

        for(int j = 0; j < str.size(); j++){

            if( i + j < str.size() && i - j >= 0){
                if(str[i + j] == str[i -j]) count++;
            }

        }

    }


    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < str.size(); j++){

            if( i + j + 1 < str.size() && i - j >= 0 ){
                if(str[i + j + 1] == str[i - j]) count++;
            }

        }
    }

}