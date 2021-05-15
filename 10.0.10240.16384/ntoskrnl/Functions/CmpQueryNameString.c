// CmpQueryNameString 
 
int __fastcall CmpQueryNameString(int a1, unsigned __int16 *a2)
{
  int v3; // r4
  int v4; // r0
  unsigned __int16 *v5; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r1
  unsigned int v12; // r2
  int v14; // [sp+8h] [bp-20h] BYREF
  int v15[7]; // [sp+Ch] [bp-1Ch] BYREF

  v3 = ObReferenceObjectByHandle(a1, 1, *(_DWORD *)CmIoFileObjectType, 0, v15, 0);
  if ( v3 < 0 )
    return v3;
  v4 = ExAllocatePoolWithTag(1, 264, 1649626435);
  v5 = (unsigned __int16 *)v4;
  if ( !v4 )
  {
LABEL_10:
    ObfDereferenceObject(v15[0]);
    return v3;
  }
  v6 = ObQueryNameStringMode(v15[0], v4, 264, &v14, 0);
  if ( v6 >= 0 )
  {
    *a2 = 0;
    v9 = *v5;
    a2[1] = v9;
    v10 = ExpAllocateStringRoutine(v9);
    *((_DWORD *)a2 + 1) = v10;
    if ( v10 )
    {
      v3 = RtlAppendUnicodeStringToString(a2, v5);
      if ( *a2 )
      {
        v11 = *((_DWORD *)a2 + 1);
        do
        {
          v12 = *a2;
          if ( *(_WORD *)(v11 + 2 * (v12 >> 1) - 2) )
            break;
          *a2 = v12 - 2;
        }
        while ( (_WORD)v12 != 2 );
      }
    }
    else
    {
      v3 = -1073741801;
    }
    if ( v5 )
      ExFreePoolWithTag((unsigned int)v5);
    goto LABEL_10;
  }
  return sub_7D1440(v6, v7, v8);
}
