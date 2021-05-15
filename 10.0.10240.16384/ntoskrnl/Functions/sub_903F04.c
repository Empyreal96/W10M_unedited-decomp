// sub_903F04 
 
void sub_903F04(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int *v6; // r4
  int v7; // r6
  int *v8; // r7
  int v9; // r3
  va_list va; // [sp+50h] [bp+8h] BYREF

  va_start(va, a6);
  while ( v6 != (int *)v7 )
  {
    if ( v6 == v8 )
    {
      PsTerminateProcess((int)v6, 1073807364);
      PsQuitNextProcessThread((int)v6);
      JUMPOUT(0x903546);
    }
    v6 = PsGetNextProcess((int)v6);
    if ( !v6 )
      goto LABEL_7;
  }
  KiStackAttachProcess(v7, 0, (int)va);
  if ( !v6 )
  {
LABEL_7:
    if ( v7 )
      v9 = v7;
    else
      v9 = (int)v8;
    DbgPrintEx(0, 0, (int)"EX debug work: Unable to find process %p\n", v9);
  }
  JUMPOUT(0x903524);
}
