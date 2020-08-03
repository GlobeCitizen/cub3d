/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:43:01 by mahnich           #+#    #+#             */
/*   Updated: 2019/12/06 17:07:55 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (!(j = 0) && i < len && haystack[i] && needle[j])
	{
		if (haystack[i] == needle[j])
		{
			while (i + j < len && (haystack[i + j] || needle[j]) &&
					haystack[i + j] == needle[j])
				j++;
			if (!needle[j] && haystack[i])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	if (needle && !needle[j])
		return ((char *)haystack);
	return (NULL);
}
