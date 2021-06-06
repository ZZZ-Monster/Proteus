void Delay(unsigned int t)
{                           
	unsigned int k;
	while(t--)
	{
		for(k=0; k<80; k++)
		;
	}
}