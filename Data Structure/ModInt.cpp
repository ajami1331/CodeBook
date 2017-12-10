struct ModInt {
    int val;
    int mod = 1e9 + 7;

    ModInt() { val = 0; }
    ModInt( int _val ) { val = _val % mod; }
    ModInt( long long _val ) { val = _val % mod; }

    ModInt& operator = ( int _val ) {
        val = _val % mod;
        return *this;
    }
    ModInt& operator = ( long long _val ) {
        val = _val % mod;
        return *this;
    }
    ModInt& operator = ( const ModInt& other ) {
        val = other.val % mod;
        return *this;
    }


    ModInt& operator += ( int _val ) {
        _val %= mod;
        val += _val;
        if( val >= mod ) val -= mod;
        return *this;
    }

    ModInt& operator += ( long long _val ) {
        _val %= mod;
        val += _val;
        if( val >= mod ) val -= mod;
        return *this;
    }

    ModInt& operator += ( const ModInt& other ) {
        int _val = other.val % mod;
        val += _val;
        if( val >= mod ) val -= mod;
        return *this;
    }

    friend ModInt operator + ( ModInt lhs, const int& rhs ) {
        lhs += rhs;
        return lhs;
    }

    friend ModInt operator + ( ModInt lhs, const long long& rhs ) {
        lhs += rhs;
        return lhs;
    }

    friend ModInt operator + ( ModInt lhs, const ModInt& rhs ) {
        lhs += rhs;
        return lhs;
    }

    ModInt& operator -= ( int _val ) {
        _val %= mod;
        val -= _val;
        while( val < 0 ) val += mod;
        if( val >= mod ) val -= mod;
        return *this;
    }

    ModInt& operator -= ( long long _val ) {
        _val %= mod;
        val -= _val;
        while( val < 0 ) val += mod;
        if( val >= mod ) val -= mod;
        return *this;
    }

    ModInt& operator -= ( const ModInt& other ) {
        int _val = other.val % mod;
        val -= _val;
        while( val < 0 ) val += mod;
        if( val >= mod ) val -= mod;
        return *this;
    }

    friend ModInt operator - ( ModInt lhs, const int& rhs ) {
        lhs -= rhs;
        return lhs;
    }

    friend ModInt operator - ( ModInt lhs, const long long& rhs ) {
        lhs -= rhs;
        return lhs;
    }

    friend ModInt operator - ( ModInt lhs, const ModInt& rhs ) {
        lhs -= rhs;
        return lhs;
    }

    ModInt& operator *= ( int _val ) {
        _val %= mod;
        val =  ((long long)val * val ) % mod;
        return *this;
    }

    ModInt& operator *= ( const ModInt& other ) {
        int _val = other.val % mod;
        val =  ((long long)val * val ) % mod;
        return *this;
    }

    friend ModInt operator * ( ModInt lhs, const int& rhs ) {
        lhs *= rhs;
        return lhs;
    }

    friend ModInt operator * ( ModInt lhs, const ModInt& rhs ) {
        lhs *= rhs;
        return lhs;
    }

    friend istream& operator >> ( istream& in, ModInt& inp ) {
        return in >> inp.val;
    }

    friend ostream& operator << ( ostream& out, const ModInt& pr ) {
        return out << pr.val;
    }

};