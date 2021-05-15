// PspGetJobLockHierarchyForAssignment 
 
int __fastcall PspGetJobLockHierarchyForAssignment(int result, int a2, int a3, int a4)
{
  int v4; // r2

  switch ( a3 )
  {
    case 1:
      goto LABEL_2;
    case 2:
      return sub_7C22C8();
    case 3:
LABEL_2:
      *(_DWORD *)a4 = 1;
      *(_DWORD *)(a4 + 4) = result;
      *(_BYTE *)(a4 + 8) = 1;
      break;
    case 4:
      *(_DWORD *)a4 = 2;
      v4 = *(_DWORD *)(a2 + 288);
      __dmb(0xBu);
      *(_DWORD *)(a4 + 4) = v4;
      *(_DWORD *)(a4 + 12) = result;
      *(_BYTE *)(a4 + 8) = 1;
      *(_BYTE *)(a4 + 16) = 0;
      break;
  }
  return result;
}
