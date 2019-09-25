/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:53:50 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/11 16:08:30 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>

#include "ex00/match.c"
#include "ex01/nmatch.c"
/*
int     test_only_match(int i, char *str1, char *str2)
{
	    int m [16] = { -1, 3, 2, 10, 6, 2, 11, 0, 29, 21, 1, 1, 1, 0, 1, 3 };
		    if (m[i] == 0)
				    {
						        if (m[i] == match(str1, str2))
									        {
												            printf("match:+");
															            return (1);
																		        }
								    }
			    else if (m[i] > 0)
					    {
							        if (match(str1, str2))
										        {
													            printf("match:+");
																            return (1);
																			        }
									        else
												        {
															            printf("match:-");
																		            return (0);
																					        }
											    }
				    return (0);
}

int     result(int num, int i, char *str1, char *str2)
{
	    printf("\n№%d. ", i);
		    if (num == 1)
				    {
						        if (test_only_match(i, str1, str2))
									            return (1);
								    }
			    else if (num == 2)
					    {
							        int m [16] = { -1, 3, 2, 10, 6, 2, 11, 0, 29, 21, 1, 1, 1, 0, 1, 3 };
									        if (m[i] >= 0)
												        {
															            if (m[i] == nmatch(str1, str2))
																			            {
																							                printf("nmatch:+  ");
																											                return (1 + test_only_match(i, str1, str2));
																															            }
																		            else
																						            {
																										                printf("nmatch:-  ");
																														                return (0 + test_only_match(i, str1, str2));
																																		            }
																					        }
											    }
				    return (0);
}

int     main(void)
{
	    int     res;
		    int     n;
			    int     num;

				    n = 1;
					    res = 0;
						num = 2;
						    printf("Input 1, if did only match\n\tor 2, if both: ");
							    scanf("%d", &num);
								    res += result( num,  n++, "barcka", "bar*c**");
									    res += result( num,  n++, "my_amazing_life", "m*_*l*");
										    res += result( num,  n++, "t;#t", "t****t");
											    res += result( num,  n++, "m ", "***");
												    res += result( num,  n++, "abcbd", "*b*");
													    res += result( num,  n++, "proprest", "*pr**");
														    res += result( num,  n++, "barghibarc", "*ar***bc");
															    res += result( num,  n++, "barghibarc", "*ar***c");
																    res += result( num,  n++, "*1**1", "*1****");
																	    res += result( num,  n++, "1***1", "1*1");
																		    res += result( num,  n++, "abrakadabra", "*abra");
																			    res += result( num,  n++, "", "");
																				    res += result( num,  n++, " ", "");
																					    res += result( num,  n++, "", "*");
																						    res += result( num,  n++, "momomo", "m*o*");
																							    if (num == 1)
																									    {
																											        printf("\n\t%d of 15\n", res);
																													        if (res == 15)
																																            printf("\tExcellent!\n");
																															    }
																								    if (num == 2)
																										    {
																												        printf("\n\t%d of 30\n", res);
																														        if (res == 30)
																																	            printf("\tExcellent!\n");
																																    }
																									    return (0);
}
*/
int		main(void)
{
	char s1[256];
	char s2[256];

	scanf("%s\n%s", s1, s2);
	printf("%d", nmatch(s1, s2));
/*		assert(match("abrabra", "*abra ") == 0);
		assert(match("main.c", "main*c") == 1);
		assert(match("main.c", "main*") == 1);
		assert(match("main.c", "*") == 1);
		assert(match("main.c", "*d") == 0);
		assert(match("main.c", "******d") == 0);
		assert(match("", "*") == 1);
		assert(match("a", "*") == 1);
		assert(match("aa", "**") == 1);
		assert(match("main.main.c", "*main.c") == 1);
		assert(match("main.c", "main.c") == 1);
		assert(match("main.c", "main.") == 0);
		assert(match("ma*in.c", "ma*.c") == 1);
		assert(match("main.c", "m*a*i*n*.*c*") == 1);*/
	return (0);
}
