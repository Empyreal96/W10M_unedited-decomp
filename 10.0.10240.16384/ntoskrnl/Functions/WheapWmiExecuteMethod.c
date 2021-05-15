// WheapWmiExecuteMethod 
 
int __fastcall WheapWmiExecuteMethod(unsigned int a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v8; // r5
  int result; // r0
  int v10; // r1
  __int64 v11; // r2
  int v12[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = (int)a4;
  v8 = *(_DWORD *)(a3 + 60);
  v12[0] = 0;
  if ( !memcmp((unsigned int)WHEAErrorSourceMethods_GUID, a1, 16) )
  {
    result = WheapWmiExecuteErrorSourceMethod(
               *(_DWORD *)(a3 + 56),
               a2 - v8,
               (int *)(v8 + a3),
               *(_DWORD *)(a3 + 64),
               (unsigned int *)v12);
  }
  else if ( !memcmp((unsigned int)WHEAErrorInjectionMethods_GUID, a1, 16) )
  {
    result = WheapWmiExecuteErrorInjectionMethod(
               *(_DWORD *)(a3 + 56),
               a2 - v8,
               (int *)(v8 + a3),
               *(_DWORD *)(a3 + 64),
               v12);
  }
  else
  {
    if ( memcmp((unsigned int)WHEAPolicyManagementMethods_GUID, a1, 16) )
    {
      result = -1073741808;
      goto LABEL_13;
    }
    result = WheapWmiExecutePolicyManagementMethod(*(_DWORD *)(a3 + 56), a2 - v8, v8 + a3, *(_DWORD *)(a3 + 64));
  }
  v10 = v12[0];
  HIDWORD(v11) = *(_DWORD *)(a3 + 60) + v12[0];
  if ( result != -1073741789 )
  {
    *(_DWORD *)a3 = HIDWORD(v11);
    *(_DWORD *)(a3 + 64) = v10;
    goto LABEL_14;
  }
  if ( a2 < 0x38 )
  {
    result = -1073741789;
LABEL_13:
    HIDWORD(v11) = 0;
    goto LABEL_14;
  }
  *(_DWORD *)a3 = 56;
  LODWORD(v11) = 32;
  *(_QWORD *)(a3 + 44) = v11;
  HIDWORD(v11) = 56;
  result = 0;
LABEL_14:
  *a4 = HIDWORD(v11);
  return result;
}
