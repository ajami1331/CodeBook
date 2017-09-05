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
} ans, inp;
