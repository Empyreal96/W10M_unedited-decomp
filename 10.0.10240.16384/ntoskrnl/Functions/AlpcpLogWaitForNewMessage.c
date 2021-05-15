// AlpcpLogWaitForNewMessage 
 
_BYTE *__fastcall AlpcpLogWaitForNewMessage(int a1, int a2, int a3, int a4)
{
  unsigned __int16 *v5; // r4
  int v6; // r7
  _BYTE *result; // r0
  _DWORD *v8; // r5
  unsigned int v9; // r2
  unsigned __int16 *v10; // [sp+0h] [bp-18h] BYREF
  int v11[5]; // [sp+4h] [bp-14h] BYREF

  v11[0] = a4;
  v5 = 0;
  v6 = 18;
  v10 = 0;
  if ( a1 )
  {
    v11[0] = -1;
    result = (_BYTE *)AlpcpGetPortNameInformation(a1, (unsigned int *)&v10, v11, -1);
    if ( (int)result < 0 )
      return result;
    v5 = v10;
    v6 = *v10 + 18;
  }
  result = (_BYTE *)ExAllocatePoolWithTag(1, v6, 1699507265);
  v8 = result;
  if ( result )
  {
    memset(result, 0, v6);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *v8 = *(_DWORD *)(v9 + 0x36C);
    v8[1] = *(_DWORD *)(v9 + 0x370);
    v8[2] = 4;
    if ( a1 )
    {
      v8[3] = (*(_DWORD *)(a1 + 244) & 6) == 2;
      memmove((int)(v8 + 4), *((_DWORD *)v5 + 1), *v5);
    }
    else
    {
      v8[3] = 0;
    }
    AlpcpInvokeLogCallbacks((int)v8, v6);
    result = (_BYTE *)ExFreePoolWithTag((unsigned int)v8);
  }
  if ( v5 )
    result = (_BYTE *)ExFreePoolWithTag((unsigned int)v5);
  return result;
}
