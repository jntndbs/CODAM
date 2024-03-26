#include "push_swap.h"

static void	sorting(t_list **head_a, t_list **head_b, t_sort *s)
{
	if (check_sort_asc(head_a) != ok && s->total_inp > 3)
	{
		weigh_sort_pb(head_a, head_b, s);
		hardsort(head_a, head_b, st_a);
		mark_sort_pa(head_a, head_b, s);
	}
	else if (check_sort_asc(head_a) != ok)
		hardsort(head_a, head_b, st_a);
}

static short	ft_pushswap(t_list **head_a, t_sort *s)
{
	t_list	*first;
	t_list	**head_b;

	first = NULL;
	head_b = &first;
	if (!*head_a)
		return (err);
	init_multiplier(s);
	sorting(head_a, head_b, s);
	free_list(head_a);
	free_list(head_b);
	return (ok);
}

// int	main(void)// TEST MAIN
// {
// 	// subject one
// 	// const char	input[] = "2 1 3 6 5 8";
// 	// 30
// 	// const char	input[] = "443333 -1 73 23 217 312 3173 -3 93 233 4232 5435 35 5343 5353 654 34 4756 772226 65426 6546 62562 26 62642562 24626542 624626 25462642 425626542 42626426 254624642";
// 	// 10
// 	// const char	input[] = "73 23 217 -4343 53535 312 3173 -3 9999 2";
// 	// 50 +-
// 	// const char	input[] = "-6255 -90207 -63182 60319 -43028 -86582 77871 -87983 42305 -23345 -1575 17690 -71254 -98662 -39284 52356 91566 -69495 -77401 -89773 -92930 52031 -69589 32942 -95586 -81215 -96909 -40424 -39183 92280 -10108 81936 78202 -95680 -6330 86525 70743 -14954 36347 -33367 13500 -22401 -83125 -15999 22828 -96358 -43253 -262 -27258 -39692";
// 	// 500
// 	// const char	input[] = "-47280 -80856 99883 -25906 -70867 -21775 -68559 -63130 -30923 1177 -2953 14752 10677 -36667 -48521 -32502 -72957 4467 -61722 -32594 50595 94171 -6873 96545 96340 68169 -39328 -78097 60696 81897 65129 85342 81139 -23176 -66926 -82799 13571 -36596 -51302 -69074 27839 -77140 43721 54208 -95108 11215 91303 25824 -41310 -69460 39656 75982 -82161 -37862 2788 4307 -93750 -40928 62277 15495 87961 -67597 81331 -41003 -72424 -19092 34324 72535 74916 -22649 10262 -46479 -45442 74458 24789 -73823 97313 -65847 -94038 95150 10942 -21098 2521 -31783 8117 -74271 -39248 -80635 -57027 7187 49455 -91049 -62474 26527 -23964 95826 46579 -43170 -78412 -49821 -81596 4783 -76730 43577 -45916 2088 60995 77312 -47481 -88895 -33130 -35366 -17357 -77593 94590 26415 -22168 -55230 7005 98008 30028 -70459 -73033 10290 22355 97907 -60798 83253 82377 -99576 -89310 -80385 58221 58758 -66126 -80208 -71530 68726 -66462 -17977 96958 34530 -19628 42086 28866 -15145 26050 -89887 63615 16625 71193 60755 -4282 -1446 -61481 90309 73404 50700 42413 -15241 85761 -81561 71492 98136 49679 87487 90921 30154 -78292 -88484 -62869 -13373 6274 63226 -62309 -50130 55333 96241 36279 -62882 58970 -36452 -99706 -80024 -89610 -18662 49096 20528 92522 39157 41575 -33795 -87724 -48900 -25492 -25712 90389 15753 90300 87625 81637 -68864 42143 33656 90282 -7239 33160 39450 50174 73567 -14839 6798 -2413 7726 9133 72217 -67239 -87565 -32662 -90855 18727 -48795 97937 59460 -26400 -43211 71663 86776 12183 -9005 68655 9001 -16925 22560 -64311 96147 -96895 -74140 -70838 54037 16670 23793 37701 -76098 77407 25062 -8603 -16998 81721 -81021 -61807 81713 -46329 -89945 -2582 87163 -2715 -53246 -83937 70089 -85234 81936 -98196 59372 -66674 -10633 54326 -92643 7783 -68987 94496 84730 96239 94871 51407 -7650 -91048 74756 -2331 -92831 2829 -87750 14475 3404 80518 99543 83442 7844 -52441 93675 80644 6364 39668 97607 -28629 -35387 -4275 7094 94815 74014 24604 11171 -27358 -44761 60872 34747 74 -45821 87053 -80437 -92268 83917 9729 72568 -41198 47466 73298 48520 -97435 47877 -12913 -86170 39557 -886 -37064 -98174 -22943 86859 -87386 13584 48590 -8781 -9215 84463 25865 92518 -77773 13018 -68498 -43375 20627 38822 -595 8586 76365 -63445 49712 28574 52216 49007 10587 15413 69237 -98456 -52695 99628 72616 49639 4241 7375 -35087 28210 -77026 -88137 -66134 -2949 44174 87264 -79862 -39410 -60202 89257 47801 20250 44626 -83628 -4470 -85412 -8410 -88674 -53886 -92652 -90406 -19067 -18877 -40047 -28198 35122 -75474 -4459 -75168 -7792 -10096 -7242 56373 -71265 6758 -81838 46791 -56838 -91399 38654 34153 74272 -9647 85365 77693 -98668 57564 -13936 31822 -81143 -63984 -43053 13698 6260 -68016 93281 4397 -80944 23017 8815 -11628 -28019 92389 -2642 -54240 10228 -93281 -87093 179 88026 50684 1002 39113 29026 -53459 -25372 78021 83902 -74623 -19364 61325 -90735 -49960 2565 89524 -39011 58504 -88838 29210 13300 -53794 229 1417 65406 55569 -75321 -2236 41970 36614 61017 -34806 -32565 -34138 -53829 -42855 -95980 43120 -92695 50048 42931 -67889 91431 -16459 -95453 -86082 80168 53045 -66903 -32353 -13677 -94033 98458 30325 93362 -28613 38260 -32089 72332 -41667 50299 18985 60650 13958 60139 -67602 29746 13447 85205";
// 	// 100
// 	// const char	input[] = "-1059 8211 -6709 2114 5831 9264 4886 2085 2998 3146 9378 -2721 3301 649 -3775 7351 3266 7110 3023 7660 5155 -4475 8044 7483 -3836 -9929 9648 -4768 -675 597 218 5965 -1585 -8015 7621 235 1174 -6104 1325 -2548 -6258 -2664 -7339 9155 6503 -4091 752 -2831 6221 7155 -7444 6706 4376 830 -5211 -5776 4140 8620 3536 -4852 770 -5140 6764 5349 -1227 -6382 2581 -4331 8003 5422 7670 -5448 6773 2951 -9151 9105 -6622 -9679 9100 -3489 -5419 7718 -7932 6425 -8320 -8370 -3338 -6232 586 -2493 -9801 9907 -2587 8276 4322 -2192 3960 4887 -3921 8909";
// 	// 200
// 	// const char	input[] = "172 258 139 112 83 174 46 45 -75 42 15 262 53 260 184 284 50 52 265 -31 125 -55 26 -89 142 220 140 74 -78 -96 -17 239 223 244 225 143 -67 130 123 264 65 233 216 60 -23 28 -90 159 211 37 146 122 131 276 -85 -42 148 -30 166 250 197 -69 23 82 254 79 -38 201 99 299 161 175 14 -33 -8 22 179 -58 11 165 -37 -70 173 275 288 -7 155 247 77 136 -32 210 198 58 40 135 176 127 -10 -63 282 30 163 47 36 178 -83 295 32 182 18 267 185 132 -88 248 169 44 -61 39 189 -45 190 202 285 151 162 -49 63 10 218 9 252 270 -87 298 -74 95 4 200 144 296 2 -59 269 154 76 -47 141 27 -25 -14 107 35 249 259 124 242 -40 -97 113 -60 219 279 208 291 204 92 217 -28 114 98 149 -84 283 -62 7 85 -12 72 -92 88 41 111 57 227 234 66 25 245 101 222 134 -34 229 -68 186 214 -3 207";
// 	// 400
// 	// const char	input[] = "128 517 647 72 216 662 973 438 486 965 300 364 689 399 344 -77 545 927 733 613 892 120 807 641 192 420 -98 320 116 949 777 551 850 512 694 448 507 703 610 -12 339 604 603 186 698 314 571 669 456 61 -81 501 857 659 383 481 -49 527 58 378 -80 706 565 215 741 849 858 866 570 903 -32 83 445 104 867 847 288 936 826 -20 140 245 696 722 937 837 141 453 265 520 992 815 428 359 972 600 396 776 472 803 138 385 -93 436 389 -39 252 384 985 524 895 721 552 674 483 179 45 132 419 999 105 715 612 606 580 218 918 -19 70 465 587 242 771 958 640 -3 957 636 340 917 836 31 469 327 872 441 548 817 148 11 -30 439 735 838 19 686 804 270 299 906 210 642 727 664 704 518 427 294 343 950 134 594 684 292 566 891 171 386 478 479 85 623 163 778 -26 293 575 280 487 -10 289 23 329 516 697 978 475 321 793 525 532 457 -92 391 -2 762 147 167 757 622 711 593 108 809 194 818 345 841 323 127 553 859 534 181 82 935 14 911 303 513 76 739 994 982 869 67 748 177 496 651 644 521 229 522 620 912 599 796 -51 984 73 983 886 966 981 255 497 95 921 356 541 634 332 650 387 360 185 203 204 899 976 -55 543 931 80 250 112 542 700 624 -76 701 677 298 196 336 247 788 786 319 274 967 554 779 -44 254 18 330 221 283 21 152 154 351 -57 50 48 533 316 910 276 202 782 -83 801 -16 736 888 68 923 763 193 -66 59 934 835 630 627 379 52 960 734 464 65 708 -8 38 -90 908 55 -63 848 783 405 894 933 825 768 637 688 269 380 440 537 488 78 322 100 33 26 546 728 510 262 493 682 607 -6 675 709 295 306 632 576 415 447 789 829 945 502 584 -36 358 261 53 679 876 914 840 79 875 758 248 -52 64 -34 107 695 126 772";
// 	// 800
// 	const char	input[] = "354 842 -9 -93 -79 195 25 418 695 -22 721 935 787 916 407 206 -29 856 390 960 914 952 505 41 991 388 81 477 285 581 962 992 658 643 548 965 65 251 283 -89 638 660 515 708 874 -36 39 -12 561 849 136 597 600 553 818 716 679 837 -98 635 500 312 591 68 664 273 -47 759 947 713 722 969 776 456 489 899 459 636 891 144 702 746 794 868 583 -40 870 872 149 121 654 366 -71 261 115 291 807 754 637 668 908 201 745 678 880 241 -19 558 788 595 116 480 448 877 948 792 256 830 194 839 930 222 199 31 247 248 -97 715 100 577 18 545 968 860 700 172 120 740 103 -66 45 33 257 957 370 862 319 576 -34 44 706 -25 202 609 186 376 535 687 934 886 -84 268 289 -57 260 -41 296 324 824 128 309 540 464 995 780 280 -75 741 783 322 258 406 130 -13 362 920 925 622 305 815 401 852 443 938 15 249 613 490 377 -30 471 821 408 719 863 95 327 649 760 43 496 996 625 949 929 988 774 353 58 -64 460 302 230 836 54 772 951 105 346 966 838 102 -65 336 267 -63 381 226 412 82 620 506 -10 972 983 378 627 -96 -56 16 152 673 -50 481 881 766 986 315 73 167 941 675 87 971 730 12 75 352 798 507 879 850 511 161 272 384 631 799 218 606 871 232 758 237 617 391 166 797 816 555 468 -44 749 457 221 527 955 544 8 413 485 989 896 779 208 565 482 692 99 906 550 647 78 -4 209 769 274 -83 122 -67 428 430 901 -91 611 598 534 -2 22 981 476 382 698 -92 585 84 -80 466 820 123 -86 784 802 19 321 17 677 572 310 6 83 939 223 114 420 286 392 890 369 903 571 785 987 902 475 97 101 335 828 463 235 422 263 252 297 615 804 98 458 454 778 690 603 435 844 921 634 400 379 298 -38 231 92 359 399 567 160 207 183 782 364 588 313 -59 444 253 165 770 5 582 -35 943 532 958 210 755 723 652 909 697 57 847 168 819 811 304 158 -77 30 479 -99 360 536 618 411 826 -68 214 -39 944 888 753 808 775 1 339 159 106 866 781 131 484 140 417 -60 646 387 869 177 71 -85 264 520 531 109 292 608 328 -27 757 538 153 306 193 67 424 396 959 -6 113 835 341 446 151 259 882 372 357 365 521 191 573 117 564 255 709 449 143 266 923 499 876 423 56 -15 355 978 707 -90 -28 171 800 347 431 596 88 833 685 250 393 867 35 340 175 182 841 386 -49 323 979 718 883 178 134 681 145 290 220 513 440 905 -88 662 705 956 853 439 742 843 974 299 216 964 348 13 806 111 227 0 447 244 851 523 526 855 425 48 752 580 -94 645 731 436 926 154 817 519 607 584 592 -33 686 932 610 539 907 246 601 329 287 -43 163 138 69 -23 696 873 894 809 940 736 575 239 693 516 452 472 404 380 389 -45 474 -42 552 846 -81 129 663 262 150 162 717 528 233 998 848 857 -5 -51 -31 90 318 72 86 243 734 21 642 549 739 470 530 812 203 190 602 429 814 990 225 133 982 349 508 659 -14 525 950 858 371 574 547 70 765 278 -3 269 672 397 157 -37 761 694 570 504 825 -69 79 -82 276 308 23 279 351 53 771 953 245 331 728 453 999 889 605 517 488 789 648 52 275 793 176 801 217 64 66 599 234 110 179 915 104 342 887 556 985 238 942 684 4 764 626 864 294 60 712 196 884 -76 805 614 492 551 977 493 374 -74 29 840 559 107 543 768 9 829 200 495 50 810 653 777 112 893 34 924 502 181 657 541 416 170 185 733 725 -54 38 132 963 928 205 590 619 997 47 503 767 954 432 518 125 284 74 937 904 385 762 277 80 337 537 345 409 -32 975 674 562 563 173 632 724";
// 	short	ret;
// 	t_list	*first;
// 	t_list	**head;
// 	t_sort	s;

// 	first = NULL;
// 	head = &first;
// 	// if (argc <= 1)
// 	// 	return (-1);
// 	if (parser((char *)input, head) != ok)
// 		return (wr_a("Error"), -1);
// 	if (indexer(head) != ok)
// 		return (wr_a("Error"), -1);
// 	assign_mark(head);
// 	s.total_inp = list_len(head);
// 	print_values(head, 'a');
// 	print_width_format("-", "");
// 	if (ft_pushswap(head, &s) != ok)
// 		return (wr_a("Error"), -1);
// 	printf("THE END\n");
// 	return (0);
// }

int	main(int argc, char **argv)
{
	short	ret;
	t_list	*first;
	t_list	**head;
	t_sort	s;

	first = NULL;
	head = &first;
	if (argc <= 1)
		return (-1);
	if (parser(input_to_string(argc, argv), head) != ok)
		return (wr_a("Error"), -1);
	if (indexer(head) != ok)
		return (wr_a("Error"), -1);
	assign_mark(head);
	s.total_inp = list_len(head);
	if (ft_pushswap(head, &s) != ok)
		return (wr_a("Error"), -1);
	return (0);
}
