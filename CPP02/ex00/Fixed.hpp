
Class	Fixed
{
	private:
		int	_value;
		const int	_rawbits = 8;
	public:
		Fixed();
		Fixed(Fixed &ori);
		~Fixed();
		Fixed operator=(Fixed ori);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
}