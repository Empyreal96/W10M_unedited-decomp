// PopSaveHiberContextWrapper 
 
int __fastcall PopSaveHiberContextWrapper(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  bool v5; // zf
  int result; // r0
  char v7; // [sp+0h] [bp-8h]

  if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
    goto LABEL_5;
  v4 = a1;
  KeSaveStateForHibernate(PoWakeState, 0, a3, a4, v7);
  v5 = PopHiberCheckResume() == 0;
  result = 1073742484;
  if ( v5 )
  {
    a1 = v4;
LABEL_5:
    result = PopSaveHiberContext(a1);
  }
  return result;
}
