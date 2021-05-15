// PiDrvDbRegisterNode 
 
int __fastcall PiDrvDbRegisterNode(int a1, char a2)
{
  unsigned int v4; // r6
  int v5; // r5
  unsigned int v6; // r5
  _WORD *v7; // r0

  v4 = 0;
  v5 = PiDrvDbCreateNode(a1);
  if ( v5 >= 0 )
  {
    if ( (MEMORY[0x20] & 1) == 0 )
    {
      v6 = MEMORY[0x10] + 32;
      v7 = (_WORD *)ExAllocatePoolWithTag(1, v6, 1650749520);
      v4 = (unsigned int)v7;
      if ( !v7 )
        return -1073741670;
      v5 = RtlStringCchPrintfW(v7, v6 >> 1, (int)L"%wZ\\%ws", 16);
      if ( v5 >= 0 )
        v5 = DrvDbRegisterDatabase(PiDrvDbCtx, a1, &PiDrvDbCtx, v4, (a2 & 8) != 0);
    }
    if ( v4 )
      ExFreePoolWithTag(v4);
  }
  return v5;
}
