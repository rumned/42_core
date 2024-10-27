/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:20:41 by zyeoh             #+#    #+#             */
/*   Updated: 2023/11/13 12:28:29 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

# define HEX_BASE 16
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_pflags_list
{
	char	invalid;
	int		out_len;
	int		w_len;
	int		pre_len;
	int		diff_len;

	int		zero;
	int		minus;
	int		hash;
	int		space;
	int		plus;
	int		precision;
}			t_pflags;

/***********************************************************************/
// ft_printf.c
/**
 * @brief Replicates Printf, takes a string followed
 * by given arguments and outputs the specifier and
 * it's flags in the string. Invalid format terminates
 * @return The length of the output
 * @param str The string to output with its specifier and flags
 * @param ... The given arguments to output
 */
int			ft_printf(const char *str, ...);

/**
 * @brief Outputs the flag 'space', starting space padding,
 * the positive sign and the space padding on the right of the specifier.
 * This function is always called twice for every output,
	the second call is to output
 * the right padding
 * @param flags The struct that holds the flags for printf
 */
void		ft_print_space(t_pflags *flags);

/**
 * @brief Outputs zero padding for the precision or the zero flag
 * @param flags The struct that holds the flags for printf
 * @param padding The number of zeros to output for padding
 */
void		ft_print_zeropadding(t_pflags *flags, int padding);

/**
 * @brief Calls the appropriate function to output based on the given character.
 * invalid format terminates
 * @param s The given specifier
 * @param flags The struct that holds the flags for ft_printf
 * @param args Holds the list of arguments given in ft_printf
 */
int			ft_print_args(const char s, t_pflags *flags, va_list args);

/**
 * @brief Parse through the flags after % and records it to flags
 * @param s The given pointer from ft_printf to parse through globally
 * @param flags The struct that holds the flags for ft_printf
 */
void		ft_print_getflags(const char **s, t_pflags *flags);

/***********************************************************************/
// ft_print_cs.c
/**
 * @brief Outputs a character in ft_printf, invalid format terminates
 * @param flags The struct that holds the flags for ft_printf
 * @param c The given ascii value to output
 */
void		ft_print_char(t_pflags *flags, int c);

/**
 * @brief Outputs a string in ft_printf, invalid format terminates
 * @param flags The struct that holds the flags for ft_printf
 * @param str The given string value to output,
	truncates if precision length is smaller
 */
void		ft_print_str(t_pflags *flags, char *str);

/**
 * @brief Outputs a percentage in ft_printf
 * @param flags The struct that holds the flags for ft_printf
 */
void		ft_print_percent(t_pflags *flags);

/***********************************************************************/
// ft_print_diu.c
/**
 * @brief Outputs an integer/denary in ft_printf, invalid format terminates
 * @param flags The struct that holds the flags for ft_printf
 * @param nbr The given value to output
 */
void		ft_print_int(t_pflags *flags, int nbr);

/**
 * @brief Outputs an unsigned integer in ft_printf, invalid format terminates
 * @param flags The struct that holds the flags for ft_printf
 * @param nbr The given value to output
 */
void		ft_print_uint(t_pflags *flags, unsigned int nbr);

/**
 * @brief Formats the given flags for denary, integer,
	unsigned int and hexadecimal.
 * @param flags The struct that holds the flags for ft_printf
 * @param nbr Checks if nbr sign to format the flags appropriately
 */
void		ft_formatflags_diux(t_pflags *flags, long long nbr);

/***********************************************************************/
// ft_print_xXp.c
/**
 * @brief Outputs the hexadecimal for both upper and lower case in ft_printf, ,
	invalid format terminates
 * @param flags The struct that holds the flags for printf
 * @param nbr The given value to convert to hexadecimal and output
 * @param baseset The string representing the baseset used to convert to
 * @param hashset The hexadecimal prefix
 */
void		ft_print_hex(t_pflags *flags, unsigned int nbr, char *baseset,
				char *hashset);

/**
 * @brief Outputs the hexadecimal to represent address, ,
	invalid format terminates
 * @param flags The struct that holds the flags for ft_printf
 * @param nbr The given value to convert to hexadecimal and output
 */
void		ft_print_ptr(t_pflags *flags, unsigned long long nbr);

/***********************************************************************/
// ft_printf_util.c
/**
 * @brief Calculates the number of digits for a number based on a base.
 * @return An int representing the number of digits
 * @param nbr The number to find the length from
 * @param base The base of the value.
 */
int			ft_numbase_ll_len(long long nbr, long base);

/**
 * @brief Calculates the number of digits for a unsigned number based on a base.
 * @return An int representing the number of digits
 * @param nbr The number to find the length from
 * @param base The base of the value.
 */
int			ft_numbase_ull_len(unsigned long long nbr, long base);

/**
 * @brief Outputs the value recursively in the format of the given baseset
 * @param nbr The value to convert and output
 * @param baseset The string representing the baseset used to convert to
 */
void		ft_putnbr_base(unsigned long long nbr, char const *baseset);

/**
 * @brief Returns the value converted to the given baseset
 * @return The string to represent the converted value
 * @param flags The struct that holds the flags for ft_printf
 * @param nbr The value to convert to the given baseset
 * @param baseset The string representing the baseset used to convert to
 */
char		*ft_custom_itoabase(t_pflags *flags, long long nbr, char *baseset);

/***********************************************************************/

#endif