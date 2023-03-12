			while (*str && *str != c)
			{
				if (*str == 34)
				{
					str++;
					while (*str && *str != 34)
						str++;
				}
				else if (*str == 39)
				{
					str++;
					while (*str && *str != 39)
						str++;
				}
				str++;
			}
			while (*str && *str == c)
				str++;
			count++;			
		}
		ifbhhsdhdshk"  kjhfsdjksfdskh"