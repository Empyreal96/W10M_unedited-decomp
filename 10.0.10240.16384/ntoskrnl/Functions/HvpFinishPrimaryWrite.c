// HvpFinishPrimaryWrite 
 
int __fastcall HvpFinishPrimaryWrite(int result, int a2, int a3)
{
  int v3; // r5
  unsigned int v5; // r2
  unsigned int v6; // r3

  v3 = result;
  if ( a2 == ((*(_DWORD *)(result + 92) & 0x100) != 0) || ((*(_DWORD *)(result + 3312) >> 3) & 1) != a3 )
    return sub_7EA728();
  if ( a2 )
  {
    if ( (*(_DWORD *)(result + 92) & 0x100) == 0 )
      goto LABEL_6;
    v6 = *(_DWORD *)(result + 92) & 0xFFFFFEFF;
  }
  else
  {
    if ( (*(_DWORD *)(result + 92) & 0x100) != 0 )
      goto LABEL_6;
    result = CmpLogEvent(REG_EVENT_FLUSH_IO_FAIL, -1073741491, result + 1976);
    v6 = *(_DWORD *)(v3 + 92) | 0x100;
  }
  *(_DWORD *)(v3 + 92) = v6;
LABEL_6:
  v5 = *(_DWORD *)(v3 + 3312);
  if ( ((v5 >> 3) & 1) != a3 )
    *(_DWORD *)(v3 + 3312) = ((unsigned __int8)v5 ^ (unsigned __int8)(8 * a3)) & 8 ^ v5;
  return result;
}
