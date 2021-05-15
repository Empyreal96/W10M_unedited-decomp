// PopSaveHiberContextWrapper 
 
int __fastcall PopSaveHiberContextWrapper(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r0
  bool v5; // zf
  int result; // r0
  char v7; // [sp+0h] [bp-8h]

  if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)
    || (v4 = KeSaveStateForHibernate(PoWakeState, 0, a3, a4, v7),
        v5 = PopHiberCheckResume(v4) == 0,
        result = 1073742484,
        v5) )
  {
    result = PopSaveHiberContext();
  }
  return result;
}
