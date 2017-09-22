struct fraction {
    ll up, down;
    ll gcd, lcm;
    void thik_kor() {
        gcd = __gcd( up, down );
        up /= gcd;
        down /= gcd;
    }
    fraction operator += ( const fraction &rhs ) {
        gcd = __gcd( down, rhs.down );
        lcm = ( down / gcd ) * rhs.down;
        up = ( ( lcm / down ) * up ) + ( ( lcm / rhs.down ) * rhs.up );
        down = lcm;
        thik_kor();
        return *this;
    }
    fraction operator -= ( const fraction &rhs ) {
        gcd = __gcd( down, rhs.down );
        lcm = ( down / gcd ) * rhs.down;
        up = ( ( lcm / down ) * up ) - ( ( lcm / rhs.down ) * rhs.up );
        down = lcm;
        thik_kor();
        return *this;
    }
    fraction operator *= ( const fraction &rhs ) {
        gcd = __gcd( up, down );
        up /= gcd;
        down /= gcd;
        gcd = __gcd( rhs.up, rhs.down );
        up =  up * ( rhs.up / gcd );
        down =  down * ( rhs.down / gcd );
        thik_kor();
        return *this;
    }
    bool operator < ( const fraction &rhs ) const {
        ll gc =  __gcd( down, rhs.down );
        ll lc = ( rhs.up / gc ) * up;
        ll a = ( lc / down ) * up;
        ll b = ( lc / rhs.down ) * rhs.up;
        return a < b;
    }
    bool operator > ( const fraction &rhs ) const {
        ll gc =  __gcd( down, rhs.down );
        ll lc = ( rhs.up / gc ) * up;
        ll a = ( lc / down ) * up;
        ll b = ( lc / rhs.down ) * rhs.up;
        return a > b;
    }
} ans, inp;
