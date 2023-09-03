#if __cplusplus < 201402L
   #define KDF_CPP14_CONSTEXPR
#else
   #define KDF_CPP14_CONSTEXPR constexpr
#endif

#if __cplusplus < 201703L
   #define KDF_NO_DISCARD
#else
   #define KDF_NO_DISCARD [[nodiscard]]
#endif

namespace kdf {
   namespace detail {
      // std::declval equivalent to not include <utility> header.
      template <typename T> T declval();
   }

   // STL-compatible containers wrapper to reverse range-based for loops.
   template <typename ContT>
   class sequence_reverser {
   public:
      using container_type = ContT;
      using value_type = typename container_type::value_type;
      using iterator = decltype( kdf::detail::declval<container_type>().rbegin() );
      using const_iterator = typename container_type::const_reverse_iterator;

      constexpr sequence_reverser(container_type& cont) noexcept : m_cont(cont) {}

      KDF_NO_DISCARD
      constexpr const_iterator cbegin() const noexcept { return m_cont.crbegin(); }
      KDF_NO_DISCARD
      constexpr const_iterator cend() const noexcept { return m_cont.crend(); }
      KDF_NO_DISCARD
      constexpr const_iterator begin() const noexcept { return cbegin(); }
      KDF_NO_DISCARD
      constexpr const_iterator end() const noexcept { return cend(); }

      KDF_NO_DISCARD KDF_CPP14_CONSTEXPR
      iterator begin() noexcept { return m_cont.rbegin(); }
      KDF_NO_DISCARD KDF_CPP14_CONSTEXPR 
      iterator end() noexcept { return m_cont.rend(); }

   private:
      container_type& m_cont;
   };

   // Reverses range-based for loop.
   template <typename ContT> KDF_NO_DISCARD
   constexpr kdf::sequence_reverser<ContT> reverse(ContT& cont) {
      return kdf::sequence_reverser<ContT>{ cont };
   }
}

