/* Start 1.inc */

func void tasks ()  {
  uchar i;
  uint  adr;

  printf ("嬪様様様様用様様様用様様様様用様様様様様様様様様冤様様様用様様様用様様様邑\n");
  printf ("� Task ID  � Start � State   � Wait for Event   � Signal � Timer � Stack �\n");
  printf ("突様様様様謡様様様謡様様様様謡様様様様様様様様様慷様様様謡様様様謡様様様裕\n");

  for (i = 0; i <= ?RTX_TASKIDX; i++)  {
    printf ("�    %2d    � ", i);
    adr = &?RTX_TASKENTRY + i*2;
    printf ("%04XH � ", uint (c:adr));
    adr = &?RTX_TASKSTATUS + i*2;
    if (RTX_CURRENTTASK == i  &&
        (uchar (i:adr+1) & 0x10))     printf ("RUNNING � ");
    else if (uchar (i:adr+1) & 0x40)  printf ("TIMEOUT � ");
    else if (uchar (i:adr+1) & 0x10)  printf ("READY   � ");
    else if (uchar (i:adr+1) & 0x03)  printf ("WAITING � ");
    else if (uchar (i:adr+1) == 0)    printf ("DELETED � ");
    else                              printf ("ILLEGAL � ");

    switch (uchar (i:adr+1) & 0x03)  {
      case 0:  printf ("                "); break;
      case 1:  printf ("SIGNAL          "); break;
      case 2:  printf ("TIMEOUT         "); break;
      case 3:  printf ("SIGNAL & TIMEOUT"); break;
    }

    if (uchar (i:adr+1) & 0x04)  printf (" �    1");
    else                         printf (" �    0");
  
    printf ("   �   %3d �", uchar (i:adr));
    adr = &?RTX_TASKSP + i;
    printf ("   %02XH �", uchar (i:adr));
    printf ("\n");
  }
  printf ("塒様様様様溶様様様溶様様様様溶様様様様様様様様様詫様様様溶様様様溶様様様余\n");
}

set f3 = "tasks ()"
bs ?RTX_NEXTTASK, 1, "printf (\"Switch to Task %d\\n\", R7)"

/* Ende 1.inc */

