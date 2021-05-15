// HvpViewMapCountPinMaskSetBits 
 
int __fastcall HvpViewMapCountPinMaskSetBits(int a1, int a2)
{
  return (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~a1 >> 16))
                         + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~a1 >> 24))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)a1 >> 8))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)a1))
       + (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~a2 >> 16))
                         + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~a2 >> 24))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)a2 >> 8))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)a2));
}
