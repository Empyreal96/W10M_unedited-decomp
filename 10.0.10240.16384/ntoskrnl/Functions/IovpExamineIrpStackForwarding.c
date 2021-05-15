// IovpExamineIrpStackForwarding 
 
int __fastcall IovpExamineIrpStackForwarding(int result, int a2, int a3, int a4, int a5, unsigned int a6, _DWORD *a7, int *a8)
{
  int v9; // r8
  int v10; // r4
  int v11; // r2
  int v12; // r3
  int v13; // r6
  bool v14; // zf
  int v15; // r3
  bool v16; // r7
  int v17; // r1

  if ( a2 )
  {
    v9 = 1;
    v10 = 0;
    goto LABEL_13;
  }
  v11 = *(char *)(a4 + 35);
  v12 = *(unsigned __int8 *)(result + 110);
  v13 = *(_DWORD *)(a4 + 96);
  v9 = v12 - v11;
  v14 = v12 == v11;
  v15 = v13 + 40 * (v12 - v11);
  v10 = v15 - 40;
  if ( !v14 )
  {
    v16 = memcmp(a6, v15 - 40, 3) == 0;
    result = memcmp(a6 + 8, v10 + 8, 16);
    if ( *(_DWORD *)(a6 + 28) == *(_DWORD *)(v10 + 28) && result == 0 && v16 )
    {
      v17 = *(_DWORD *)(a6 + 32);
      if ( v17 == *(_DWORD *)(v10 + 32)
        && *(_DWORD *)(a6 + 36) == *(_DWORD *)(v10 + 36)
        && *(unsigned __int8 *)(a6 + 3) == *(unsigned __int8 *)(v10 + 3) )
      {
        if ( v17 )
        {
          result = IovUtilMultipleDevicesSameDriver(*(_DWORD *)(v10 + 24));
          if ( !result )
          {
            result = VfErrorReport1(519, a5, a4);
            *(_DWORD *)(a6 + 32) = 0;
            *(_BYTE *)(a6 + 3) = 0;
          }
          goto LABEL_13;
        }
      }
      else if ( v17 )
      {
        goto LABEL_13;
      }
      *(_DWORD *)(v13 - 8) = IovpInternalCompletionTrap;
      *(_DWORD *)(v13 - 4) = v13;
      *(_BYTE *)(v13 - 37) = -32;
      goto LABEL_13;
    }
  }
LABEL_13:
  *a7 = v10;
  *a8 = v9;
  return result;
}
